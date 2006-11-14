/* utf8convert.cc: convert a string to UTF-8 encoding.
 *
 * Copyright (C) 2006 Olly Betts
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include <config.h>

#include "utf8convert.h"

#include <algorithm>
#include <string>

#include <errno.h>
#include <iconv.h>
#include <string.h>
#ifdef HAVE_STRINGS_H
# include <strings.h> // Needed on Solaris for strcasecmp
#endif

#ifdef _MSC_VER
# define strcasecmp stricmp
#endif

using namespace std;

void
convert_to_utf8(string & text, const string & charset)
{
    // Shortcut if it's already in utf8!
    if (charset.size() == 5 && strcasecmp(charset.c_str(), "utf-8") == 0)
	return;
    if (charset.size() == 4 && strcasecmp(charset.c_str(), "utf8") == 0)
	return;

    // Nobody has told us what charset it's in, so do as little work as
    // possible!
    if (charset.empty())
	return;

    char buf[1024];

    iconv_t conv = iconv_open("UTF-8", charset.c_str());
    if (conv == (iconv_t)-1) return;

    string tmp;

    ICONV_INPUT_TYPE in = const_cast<char *>(text.c_str());
    size_t in_len = text.size();
    while (in_len) {
	char * out = buf;
	size_t out_len = sizeof(buf);
	if (iconv(conv, &in, &in_len, &out, &out_len) == size_t(-1) &&
	    errno != E2BIG) {
	    // FIXME: how to handle this?
	    break;
	}
	tmp.append(buf, out - buf);
    }

    (void)iconv_close(conv);

    swap(text, tmp);
}

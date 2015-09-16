/* Copyright © 2008-2015 Jakub Wilk <jwilk@jwilk.net>
 *
 * This file is part of pdfdjvu.
 *
 * pdf2djvu is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * pdf2djvu is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#ifndef PDF2DJVU_STRING_UTILS_HH
#define PDF2DJVU_STRING_UTILS_HH

#include <string>
#include <vector>

namespace string {

    void split(const std::string &s, char c, std::vector<std::string> &result);

}

#endif

// vim:ts=4 sts=4 sw=4 et

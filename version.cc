/* Copyright © 2015 Jakub Wilk <jwilk@jwilk.net>
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

#include "version.hh"

#include <sstream>

#include <libdjvu/ddjvuapi.h>

#include "autoconf.hh"
#include "system.hh"

static std::string get_djvulibre_version()
{
#if DDJVUAPI_VERSION >= 20
    std::string v = ddjvu_get_version_string();
    if (v.compare(0, 10, "DjVuLibre-") == 0)
        v.erase(0, 10);
    return v;
#else
    return DJVULIBRE_VERSION_STRING;
#endif
}

#if HAVE_LIBXSLT

#include <libxslt/xslt.h>

static std::string get_libxslt_version()
{
    return string_printf("%d.%d.%d",
        xsltLibxsltVersion / 10000,
        (xsltLibxsltVersion / 100) % 100,
        xsltLibxsltVersion % 100
    );
}

static std::string get_libxml2_version()
{
    return string_printf("%d.%d.%d",
        xsltLibxmlVersion / 10000,
        (xsltLibxmlVersion / 100) % 100,
        xsltLibxmlVersion % 100
    );
}

#endif

#if HAVE_GRAPHICSMAGICK

#include <Magick++.h>

static std::string get_gm_version()
{
    unsigned long n;
    std::stringstream stream(
        MagickLib::GetMagickVersion(&n)
    );
    std::string junk, result;
    stream >> junk >> result;
    return result;
}

#endif

const std::string get_version()
{
    std::ostringstream stream;
    stream << PACKAGE_STRING;
    stream << " (DjVuLibre " << get_djvulibre_version();
    stream << ", Poppler " POPPLER_VERSION_STRING;
#if HAVE_GRAPHICSMAGICK
    stream << ", GraphicsMagick++ " << get_gm_version();
#endif
#if HAVE_LIBXSLT
    stream << ", GNOME XSLT " << get_libxslt_version();
    stream << ", GNOME XML " << get_libxml2_version();
#endif
    stream << ")";
    return stream.str();
}

const std::string get_multiline_version()
{
    std::ostringstream stream;
    stream << PACKAGE_STRING << "\n";
    stream << "+ DjVuLibre " << get_djvulibre_version() << "\n";
    stream << "+ Poppler " POPPLER_VERSION_STRING << "\n";
#if HAVE_GRAPHICSMAGICK
    stream << "+ GraphicsMagick++ " << get_gm_version() << " (Q" << QuantumDepth << ")\n";
#endif
#if HAVE_LIBXSLT
    stream << "+ GNOME XSLT " << get_libxslt_version() << "\n";
    stream << "+ GNOME XML " << get_libxml2_version() << "\n";
#endif
    return stream.str();
}

// vim:ts=4 sts=4 sw=4 et

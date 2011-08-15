/* ============================================================
 *
 * This file is a part of the RSB project
 *
 * Copyright (C) 2011 by Ingo Lütkebohle <iluetkeb.techfak.uni-bielefeld.de>                                      
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * ============================================================ */

#pragma once



class TIDEException : public std::exception {
private:
    const std::string msg;
public:
    TIDEException(const std::string&);
    ~TIDEException() throw ();
    virtual const char* what() const throw ();
};

class IOException : public TIDEException {
public:
    IOException(const std::string& msg);
};

class IllegalArgumentException : public TIDEException {
public:
    IllegalArgumentException(const std::string& msg);
};

/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/

#ifndef _CC_SDKBOX_H_
#define _CC_SDKBOX_H_

namespace sdkbox {

    void init( const char* application_token, const char* application_key );
    void init( const char* application_token, const char* application_key, bool debug );
}

#endif//_CC_SDKBOX_H_
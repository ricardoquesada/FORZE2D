// DO NOT MODIFY THE HEADERS IF FORZE IS ALREADY COMPILED AS A STATIC LIBRARY
#ifndef __FZTEXTURE_SHADER_H_INCLUDED__
#define __FZTEXTURE_SHADER_H_INCLUDED__
/*
 * FORZE ENGINE: http://forzefield.com
 *
 * Copyright (c) 2011-2012 FORZEFIELD Studios S.L.
 * Copyright (c) 2012 Manuel Martínez-Almeida
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 @author Manuel Martínez-Almeida
 */

#include "FZPlatforms.h"

#if FZ_GL_SHADERS

const char __fz_frag_TEX[] =
"#ifdef GL_ES \n\
precision lowp float; \n\
varying mediump vec2 v_texCoord; \n\
uniform lowp sampler2D u_texture; \n\
#else \n\
varying vec2 v_texCoord; \n\
uniform sampler2D u_texture; \n\
#endif \n\
\
void main() { \n\
gl_FragColor = texture2D(u_texture, v_texCoord); \n\
}";


const char __fz_vert_mat_TEX[] =
"attribute vec4 a_position; \n\
attribute vec2 a_texCoord; \n\
uniform	mat4 u_MVMatrix; \n\
#ifdef GL_ES \n\
varying mediump vec2 v_texCoord; \n\
#else \n\
varying vec2 v_texCoord; \n\
#endif \n\
\
void main() { \n\
    gl_Position = u_MVMatrix * a_position; \n\
    v_texCoord = a_texCoord; \n\
}";


#endif
#endif

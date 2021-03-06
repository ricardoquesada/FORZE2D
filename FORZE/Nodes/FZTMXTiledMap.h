// DO NOT MODIFY THE HEADERS IF FORZE IS ALREADY COMPILED AS A STATIC LIBRARY
#ifndef __FZTMXTILEDMAP_H_INCLUDED__
#define __FZTMXTILEDMAP_H_INCLUDED__
/*
 * FORZE ENGINE: http://forzefield.com
 *
 * Copyright (c) 2011-2012 FORZEFIELD Studios S.L.
 * Copyright (c) 2012 Manuel Martínez-Almeida
 * Copyright (c) 2008-2010 Ricardo Quesada
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

#include "FZNode.h"
#include "FZConfig.h"
#include "FZTypes.h"
#include "FZSpriteBatch.h"
#include "FZTMXParser.h"


using namespace STD;

namespace FORZE {
    
    class TMXLayer;
    class TMXTiledMap : public SpriteBatch
    {
        friend class TMXLayer;
        
    protected:
        TMXMapInfo m_mapInfo;

        virtual void insertChild(Node*) override;
        
    public:
        //! Constructs a TMXTiledMap node from the TMX file.
        //! This constructor initializes an instance of the TMXParser.
        explicit TMXTiledMap(const char *tmxfilename);
        
        
        TMXTilesetInfo* getTileset() {
            return &m_mapInfo.getTileset();
        }
        
        // Redefined
        virtual void render(char) override;
    };
}
#endif

/*
Copyright (C) 2004-2008 Grame

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software 
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

*/

#ifndef __JackProcessSync__
#define __JackProcessSync__

#include "JackPlatformPlug.h"
#include "JackPosixMutex.h"
#include <sys/time.h>
#include <unistd.h>

namespace Jack
{

/*!
\brief  A synchronization primitive built using a condition variable.
*/

class JackProcessSync : public JackPosixMutex
{

    private:

        pthread_cond_t fCond;   // Condition variable

    public:

        JackProcessSync():JackPosixMutex()
        {
            pthread_cond_init(&fCond, NULL);
        }

        ~JackProcessSync()
        {
            pthread_cond_destroy(&fCond);
        }

        bool TimedWait(long usec);
        bool LockedTimedWait(long usec);
        
        void Wait();
        void LockedWait();
         
        void Signal();
        void LockedSignal();
         
        void SignalAll();
        void LockedSignalAll();
  
};

} // end of namespace

#endif

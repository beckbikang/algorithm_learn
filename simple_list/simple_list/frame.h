#ifndef __FRAME__
#define __FRAME__
#include "list.h"

int alloc_frame(List *frames);

int free_frame(List *frames, int frame_number);



#endif //__FRAME__
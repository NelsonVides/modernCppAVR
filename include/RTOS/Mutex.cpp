#include "Mutex.h"

using namespace vAVR::Sync;

TID _G_TASK_ID_ = 0x0;
bool _G_SAFE_CALL_FLAG = false;
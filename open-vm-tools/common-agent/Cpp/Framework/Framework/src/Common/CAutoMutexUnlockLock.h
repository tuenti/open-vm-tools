/*
 *	 Author: bwilliams
 *  Created: Oct 21, 2014
 *
 *	Copyright (c) 2011 Vmware, Inc.  All rights reserved.
 *	-- VMware Confidential
 */

#ifndef CAUTOMUTEXUNLOCKLOCK_H_
#define CAUTOMUTEXUNLOCKLOCK_H_


#include "Common/CAutoMutex.h"
#include "Common/CAutoRecMutex.h"

namespace Caf {

class COMMONAGGREGATOR_LINKAGE CAutoMutexUnlockLock {
public:
	CAutoMutexUnlockLock(
			SmartPtrCAutoMutex& mutex,
			const char* className = NULL,
			const char* funcName = NULL,
			const int32 lineNumber = 0);

	CAutoMutexUnlockLock(
			SmartPtrCAutoRecMutex& recMutex,
			const char* className = NULL,
			const char* funcName = NULL,
			const int32 lineNumber = 0);

	~CAutoMutexUnlockLock();

private:
	SmartPtrCAutoMutex _mutex;
	SmartPtrCAutoRecMutex _recMutex;

	std::string _className;
	std::string _funcName;
	int32 _lineNumber;

private:
	CAF_CM_CREATE;
	CAF_CM_DECLARE_NOCOPY(CAutoMutexUnlockLock);
};
}

#endif /* CAUTOMUTEXUNLOCKLOCK_H_ */

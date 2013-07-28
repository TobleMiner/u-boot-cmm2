/**
 * @file IxOsalOsSemaphore.c (eCos)
 *
 * @brief Implementation for semaphore and mutex.
 *
 *
 * @par
 * IXP400 SW Release version 1.5
 *
 * -- Copyright Notice --
 *
 * @par
 * Copyright 2001-2005, Intel Corporation.
 * All rights reserved.
 *
 * @par
 * SPDX-License-Identifier:	BSD-3-Clause
 * @par
 * -- End of Copyright Notice --
 */

#include "IxOsal.h"
#include "IxNpeMhReceive_p.h"

/* Define a large number */
#define IX_OSAL_MAX_LONG (0x7FFFFFFF)

/* Max timeout in MS, used to guard against possible overflow */
#define IX_OSAL_MAX_TIMEOUT_MS (IX_OSAL_MAX_LONG/HZ)


PUBLIC IX_STATUS
ixOsalSemaphoreInit (IxOsalSemaphore * sid, UINT32 start_value)
{
    diag_printf("%s called\n", __FUNCTION__);
    return IX_SUCCESS;
}

/**
 * DESCRIPTION: If the semaphore is 'empty', the calling thread is blocked.
 *              If the semaphore is 'full', it is taken and control is returned
 *              to the caller. If the time indicated in 'timeout' is reached,
 *              the thread will unblock and return an error indication. If the
 *              timeout is set to 'IX_OSAL_WAIT_NONE', the thread will never block;
 *              if it is set to 'IX_OSAL_WAIT_FOREVER', the thread will block until
 *              the semaphore is available.
 *
 *
 */


PUBLIC IX_STATUS
ixOsalSemaphoreWait (IxOsalOsSemaphore * sid, INT32 timeout)
{
    diag_printf("%s called\n", __FUNCTION__);
    return IX_SUCCESS;
}

/*
 * Attempt to get semaphore, return immediately,
 * no error info because users expect some failures
 * when using this API.
 */
PUBLIC IX_STATUS
ixOsalSemaphoreTryWait (IxOsalSemaphore * sid)
{
    diag_printf("%s called\n", __FUNCTION__);
    return IX_FAIL;
}

/**
 *
 * DESCRIPTION: This function causes the next available thread in the pend queue
 *              to be unblocked. If no thread is pending on this semaphore, the
 *              semaphore becomes 'full'.
 */
PUBLIC IX_STATUS
ixOsalSemaphorePost (IxOsalSemaphore * sid)
{
    diag_printf("%s called\n", __FUNCTION__);
    return IX_SUCCESS;
}

PUBLIC IX_STATUS
ixOsalSemaphoreGetValue (IxOsalSemaphore * sid, UINT32 * value)
{
    diag_printf("%s called\n", __FUNCTION__);
    return IX_FAIL;
}

PUBLIC IX_STATUS
ixOsalSemaphoreDestroy (IxOsalSemaphore * sid)
{
    diag_printf("%s called\n", __FUNCTION__);
    return IX_FAIL;
}

/****************************
 *    Mutex
 ****************************/

static void drv_mutex_init(IxOsalMutex *mutex)
{
	*mutex = 0;
}

static void drv_mutex_destroy(IxOsalMutex *mutex)
{
	*mutex = -1;
}

static int drv_mutex_trylock(IxOsalMutex *mutex)
{
	int result = true;

	if (*mutex == 1)
		result = false;

	return result;
}

static void drv_mutex_unlock(IxOsalMutex *mutex)
{
	if (*mutex == 1)
		printf("Trying to unlock unlocked mutex!");

	*mutex = 0;
}

PUBLIC IX_STATUS
ixOsalMutexInit (IxOsalMutex * mutex)
{
    drv_mutex_init(mutex);
    return IX_SUCCESS;
}

PUBLIC IX_STATUS
ixOsalMutexLock (IxOsalMutex * mutex, INT32 timeout)
{
    int tries;

    if (timeout == IX_OSAL_WAIT_NONE) {
	if (drv_mutex_trylock(mutex))
	    return IX_SUCCESS;
	else
	    return IX_FAIL;
    }

    tries = (timeout * 1000) / 50;
    while (1) {
	if (drv_mutex_trylock(mutex))
	    return IX_SUCCESS;
	if (timeout != IX_OSAL_WAIT_FOREVER && tries-- <= 0)
	    break;
	udelay(50);
    }
    return IX_FAIL;
}

PUBLIC IX_STATUS
ixOsalMutexUnlock (IxOsalMutex * mutex)
{
    drv_mutex_unlock(mutex);
    return IX_SUCCESS;
}

/*
 * Attempt to get mutex, return immediately,
 * no error info because users expect some failures
 * when using this API.
 */
PUBLIC IX_STATUS
ixOsalMutexTryLock (IxOsalMutex * mutex)
{
    if (drv_mutex_trylock(mutex))
	return IX_SUCCESS;
    return IX_FAIL;
}

PUBLIC IX_STATUS
ixOsalMutexDestroy (IxOsalMutex * mutex)
{
    drv_mutex_destroy(mutex);
    return IX_SUCCESS;
}

PUBLIC IX_STATUS
ixOsalFastMutexInit (IxOsalFastMutex * mutex)
{
    return ixOsalMutexInit(mutex);
}

PUBLIC IX_STATUS ixOsalFastMutexTryLock(IxOsalFastMutex *mutex)
{
    return ixOsalMutexTryLock(mutex);
}


PUBLIC IX_STATUS
ixOsalFastMutexUnlock (IxOsalFastMutex * mutex)
{
    return ixOsalMutexUnlock(mutex);
}

PUBLIC IX_STATUS
ixOsalFastMutexDestroy (IxOsalFastMutex * mutex)
{
    return ixOsalMutexDestroy(mutex);
}

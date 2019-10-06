/*
 * Copyright (C) 2014 Samsung Electronics
 * Przemyslaw Marczak <p.marczak@samsung.com>
 *
 * SDPX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <errno.h>

#define ERRNO_MSG(errno, msg)	msg
#define SAME_AS(x)		(const char *)&errno_message[x]

static const char * const errno_message[] = {
	ERRNO_MSG(0, "Success"),
	ERRNO_MSG(EPERM, "Operation not permitted"),
	ERRNO_MSG(ENOENT, "No such file or directory"),
	ERRNO_MSG(ESRCH, "No such process"),
	ERRNO_MSG(EINTR, "Interrupted system call"),
	ERRNO_MSG(EIO, "I/O error"),
	ERRNO_MSG(ENXIO, "No such device or address"),
	ERRNO_MSG(E2BIG, "Argument list too long"),
	ERRNO_MSG(ENOEXEC, "Exec format error"),
	ERRNO_MSG(EBADF, "Bad file number"),
	ERRNO_MSG(ECHILD, "No child processes"),
	ERRNO_MSG(EAGAIN, "Try again"),
	ERRNO_MSG(ENOMEM, "Out of memory"),
	ERRNO_MSG(EACCES, "Permission denied"),
	ERRNO_MSG(EFAULT, "Bad address"),
	ERRNO_MSG(ENOTBLK, "Block device required"),
	ERRNO_MSG(EBUSY, "Device or resource busy"),
	ERRNO_MSG(EEXIST, "File exists"),
	ERRNO_MSG(EXDEV, "Cross-device link"),
	ERRNO_MSG(ENODEV, "No such device"),
	ERRNO_MSG(ENOTDIR, "Not a directory"),
	ERRNO_MSG(EISDIR, "Is a directory"),
	ERRNO_MSG(EINVAL, "Invalid argument"),
	ERRNO_MSG(ENFILE, "File table overflow"),
	ERRNO_MSG(EMFILE, "Too many open files"),
	ERRNO_MSG(ENOTTY, "Not a typewriter"),
	ERRNO_MSG(ETXTBSY, "Text file busy"),
	ERRNO_MSG(EFBIG, "File too large"),
	ERRNO_MSG(ENOSPC, "No space left on device"),
	ERRNO_MSG(ESPIPE, "Illegal seek"),
	ERRNO_MSG(EROFS, "Read-only file system"),
	ERRNO_MSG(EMLINK, "Too many links"),
	ERRNO_MSG(EPIPE, "Broken pipe"),
	ERRNO_MSG(EDOM, "Math argument out of domain of func"),
	ERRNO_MSG(ERANGE, "Math result not representable"),
	ERRNO_MSG(EDEADLK, "Resource deadlock would occur"),
	ERRNO_MSG(ENAMETOOLONG, "File name too long"),
	ERRNO_MSG(ENOLCK, "No record locks available"),
	ERRNO_MSG(ENOSYS, "Function not implemented"),
	ERRNO_MSG(ENOTEMPTY, "Directory not empty"),
	ERRNO_MSG(ELOOP, "Too many symbolic links encountered"),
	ERRNO_MSG(EWOULDBLOCK, SAME_AS(EAGAIN)),
	ERRNO_MSG(ENOMSG, "No message of desired type"),
	ERRNO_MSG(EIDRM, "Identifier removed"),
	ERRNO_MSG(ECHRNG, "Channel number out of range"),
	ERRNO_MSG(EL2NSYNC, "Level 2 not synchronized"),
	ERRNO_MSG(EL3HLT, "Level 3 halted"),
	ERRNO_MSG(EL3RST, "Level 3 reset"),
	ERRNO_MSG(ELNRNG, "Link number out of range"),
	ERRNO_MSG(EUNATCH, "Protocol driver not attached"),
	ERRNO_MSG(ENOCSI, "No CSI structure available"),
	ERRNO_MSG(EL2HLT, "Level 2 halted"),
	ERRNO_MSG(EBADE, "Invalid exchange"),
	ERRNO_MSG(EBADR, "Invalid request descriptor"),
	ERRNO_MSG(EXFULL, "Exchange full"),
	ERRNO_MSG(ENOANO, "No anode"),
	ERRNO_MSG(EBADRQC, "Invalid request code"),
	ERRNO_MSG(EBADSLT, "Invalid slot"),
	ERRNO_MSG(EDEADLOCK, SAME_AS(EDEADLK)),
	ERRNO_MSG(EBFONT, "Bad font file format"),
	ERRNO_MSG(ENOSTR, "Device not a stream"),
	ERRNO_MSG(ENODATA, "No data available"),
	ERRNO_MSG(ETIME, "Timer expired"),
	ERRNO_MSG(ENOSR, "Out of streams resources"),
	ERRNO_MSG(ENONET, "Machine is not on the network"),
	ERRNO_MSG(ENOPKG, "Package not installed"),
	ERRNO_MSG(EREMOTE, "Object is remote"),
	ERRNO_MSG(ENOLINK, "Link has been severed"),
	ERRNO_MSG(EADV, "Advertise error"),
	ERRNO_MSG(ESRMNT, "Srmount error"),
	ERRNO_MSG(ECOMM, "Communication error on send"),
	ERRNO_MSG(EPROTO, "Protocol error"),
	ERRNO_MSG(EMULTIHOP, "Multihop attempted"),
	ERRNO_MSG(EDOTDOT, "RFS specific error"),
	ERRNO_MSG(EBADMSG, "Not a data message"),
	ERRNO_MSG(EOVERFLOW, "Value too large for defined data type"),
	ERRNO_MSG(ENOTUNIQ, "Name not unique on network"),
	ERRNO_MSG(EBADFD, "File descriptor in bad state"),
	ERRNO_MSG(EREMCHG, "Remote address changed"),
	ERRNO_MSG(ELIBACC, "Can not access a needed shared library"),
	ERRNO_MSG(ELIBBAD, "Accessing a corrupted shared library"),
	ERRNO_MSG(ELIBSCN, ".lib section in a.out corrupted"),
	ERRNO_MSG(ELIBMAX, "Attempting to link in too many shared libraries"),
	ERRNO_MSG(ELIBEXEC, "Cannot exec a shared library directly"),
	ERRNO_MSG(EILSEQ, "Illegal byte sequence"),
	ERRNO_MSG(ERESTART, "Interrupted system call should be restarted"),
	ERRNO_MSG(ESTRPIPE, "Streams pipe error"),
	ERRNO_MSG(EUSERS, "Too many users"),
	ERRNO_MSG(ENOTSOCK, "Socket operation on non-socket"),
	ERRNO_MSG(EDESTADDRREQ, "Destination address required"),
	ERRNO_MSG(EMSGSIZE, "Message too long"),
	ERRNO_MSG(EPROTOTYPE, "Protocol wrong type for socket"),
	ERRNO_MSG(ENOPROTOOPT, "Protocol not available"),
	ERRNO_MSG(EPROTONOSUPPORT, "Protocol not supported"),
	ERRNO_MSG(ESOCKTNOSUPPORT, "Socket type not supported"),
	ERRNO_MSG(EOPNOTSUPP, "Operation not supported on transport endpoint"),
	ERRNO_MSG(EPFNOSUPPORT, "Protocol family not supported"),
	ERRNO_MSG(AFNOSUPPORT, "Address family not supported by protocol"),
	ERRNO_MSG(EADDRINUSE, "Address already in use"),
	ERRNO_MSG(EADDRNOTAVAIL, "Cannot assign requested address"),
	ERRNO_MSG(ENETDOWN, "Network is down"),
	ERRNO_MSG(ENETUNREACH, "Network is unreachable"),
	ERRNO_MSG(ENETRESET, "Network dropped connection because of reset"),
	ERRNO_MSG(ECONNABORTED, "Software caused connection abort"),
	ERRNO_MSG(ECONNRESET, "Connection reset by peer"),
	ERRNO_MSG(ENOBUFS, "No buffer space available"),
	ERRNO_MSG(EISCONN, "Transport endpoint is already connected"),
	ERRNO_MSG(ENOTCONN, "Transport endpoint is not connected"),
	ERRNO_MSG(ESHUTDOWN, "Cannot send after transport endpoint shutdown"),
	ERRNO_MSG(ETOOMANYREFS, "Too many references: cannot splice"),
	ERRNO_MSG(ETIMEDOUT, "Connection timed out"),
	ERRNO_MSG(ECONNREFUSED, "Connection refused"),
	ERRNO_MSG(EHOSTDOWN, "Host is down"),
	ERRNO_MSG(EHOSTUNREACH, "No route to host"),
	ERRNO_MSG(EALREADY, "Operation already in progress"),
	ERRNO_MSG(EINPROGRESS, "Operation now in progress"),
	ERRNO_MSG(ESTALE, "Stale NFS file handle"),
	ERRNO_MSG(EUCLEAN, "Structure needs cleaning"),
	ERRNO_MSG(ENOTNAM, "Not a XENIX named type file"),
	ERRNO_MSG(ENAVAIL, "No XENIX semaphores available"),
	ERRNO_MSG(EISNAM, "Is a named type file"),
	ERRNO_MSG(EREMOTEIO, "Remote I/O error"),
	ERRNO_MSG(EDQUOT, "Quota exceeded"),
	ERRNO_MSG(ENOMEDIUM, "No medium found"),
	ERRNO_MSG(EMEDIUMTYPE, "Wrong medium type"),
	/* Message for unsupported error numbers */
	ERRNO_MSG(0, "Unknown error"),
};

const char *errno_str(int errno)
{
	if (errno >= 0)
		return errno_message[0];

	errno = -errno;
	if (errno >= ARRAY_SIZE(errno_message))
		errno = ARRAY_SIZE(errno_message) - 1;

	return errno_message[errno];
}

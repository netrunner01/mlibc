#include <errno.h>

#include <mlibc/all-sysdeps.hpp>
#include <mlibc/debug.hpp>

namespace mlibc {

int Sysdeps<Capget>::operator()(cap_user_header_t, cap_user_data_t) {
	// We do not implement capabilities. Return ENOSYS rather than reporting success while
	// leaving the caller's cap_user_data output UNINITIALIZED (a silent lie plus an
	// uninitialized read of the caller's stack). See DEF-15.
	mlibc::infoLogger() << "mlibc: capget is unimplemented (ENOSYS)" << frg::endlog;
	return ENOSYS;
}

int Sysdeps<Capset>::operator()(cap_user_header_t, const cap_user_data_t) {
	mlibc::infoLogger() << "mlibc: capset is a no-op!" << frg::endlog;
	return 0;
}

} // namespace mlibc

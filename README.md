In 2000 Per Liden started CRUX-Linux, a distro based on simplicity.  The
idea for the ports system was influenced by BSD ports, but written in sh
and C++, the Pkgfiles which define how a package  should  be  build  are
nothing but simple shell-scripts.

Cruxports for OpenBSD is a port/rewrite  of  the  CRUX  ports-system  to
OpenBSD, and is completely written in shell-script.

Now I hear you say: "What's wrong with the normal ports?" Well...  wrong
is a big word. It's just a matter of personal preference  I  think.  But
let me give you a list of reasons why I prefer cruxports.

 * Lightweight.
 * Always the latest versions of software, no matter which  release  you
   use.
 * CRUX ports are much easier to create and maintain since the ports are
   shell-based.
 * Portable, anyone can read and understand a cruxport.
 * Dependencies are optional.
 * It's not trying to be braindead-proof.
 * No checking of md5sum on uninstall of files.
 * Files in /etc are installed, and maintained with a  mergemaster  like
   application (rejmerge) in a sane and easy way.
 * You can easily share your own ports with others with httpup.
 * Does not conflict with other package-managers.
 * You can build packages from alternative sources like binaries or git
 * You can install packages on systems with very little resources.

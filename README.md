share
====

<h1>The Share Library Suite</h1>

This is the official source code repository for the share runtime library and utility suite. 

Version: 3.1

API: <a href="http://www.sharelib.net/libshare/">Share Library Documentation</a>

<h2>Quick Instructions</h2>

<h3>Share Library Build Instructions</h3>

On linux, a build can be performed by running the following:
<i><small><pre>
  git clone https://github.com/neonatura/share
  cd share
  mkdir build
  cd build
  ../configure
  make
  make install
</pre></small><i>

 Note: Use --libdir=/usr/lib64 on Cent OS platforms.

<h3>Build Dependencies</h3>

You must install the 'gcc-java' package in order to provide the "jni.h" gcc header file for the java API to compile correctly. To install on linux run 'yum install gcc-java' or 'apt-get install gcc-java'.

SWIG is optional. Pre-built source code has been generated as part of the distritution. To install on linux run 'yum install swig' or 'apt-get install swig'.

<h2>Library Specifications</h2> 

<h3>Features</h3>

<h4>Networking / IPC</h4>
Provides simplified standard socket processing in addition to a proprietary ESL (encoded stream layer) protocol for encryption communications.

A "peer tracking" interface provides the ability to keep track of peer connections based on their reliability.

The network routines are compatible with operating systems which can handle more than 64k socket buffer size and more than 1024 sockets per process.

The share library provides simulated block devices in order to stream file data between multiple endpoints. Permissions allow control of whether the stream is readable, writeable, or executable. 

The share library supports POSIX style share memory mapping, message queues, and memory mapped files. The mapped files may preside on a local file system or a shared file.

<h4>Memory Routines</h4>
A full set of SHA, ECDSA, and other encryption methods are supplied. Binary encoding methods are also provided for base32, base58, base64, and more. See the shalg utility program for example usage.

Hierarchial objects storage methods for B-Tree, JSON, SHZ (share compression), common zlib, and more is provided.

Integrated support for big numbers is provided using the libshare proprietary method or the standard MPI functionality.

Memory buffers and pools are provided for dynamic storage.

<h4>File-system Routines</h4>
A proprietary embedded file-system is provided which includes extended attributes such as milli-second precision, multiple computer file-sharing, file compression, file encryption, sqlite databases, source code revision history, and more.

The share library introduces a flexible approach to inter-process communication by combining a shared memory map with a versioned file system.

The sharefs file system utilitizes the operating system file cache in order to simulate a shared memory segment. 

File data is saved persistently with access rights based on the peer reading or writing the file. Several version of the same file may exist, and based on the trust level with another sharefs peer multiple copies of the same file may exist.

The structure of the file system is designed in order to allow for multiple hierarchies simutaneously. The file system contains "meta file" definitions which allow for a program dynamically interpret how to handle file data. 

<h4>Portability</h4>

The share library supports API calls from both php and java.

The libshare library introduces a new programming language called "SEXE" which is based on the LUA scripting language provided by puerto-rico university. The suite includes the "sxc" (SEXE binary compiler) and "sx" (SEXE executor) programs for respectively compiling and running SEXE programs. In addition, SEXE programs can be run directly from the "nsh" shell.

Link against the "share_sexe" library for access to the SEXE runtime calls.

The share library can be compiled on the unix (posix) and windows based platforms.

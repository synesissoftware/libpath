/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/result_codes/enumerations/rc.h
 *
 * Purpose: Result codes defined for libpath library.
 *
 * Created: 9th November 2012
 * Updated: 10th February 2024
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2012-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


#if 0
#elif defined(LIBPATH_DEFINING_STRING_VARIABLES)
# define LIBPATH_DEFINE_ResultCode_(en, value, shimString, helpString)          LOOKUP_STR_DECL_(libpath_ResultCode_##en, #helpString);
# undef LIBPATH_DEFINING_STRING_VARIABLES

#elif defined(LIBPATH_DEFINING_STRING_ARRAY)

# define LIBPATH_DEFINE_ResultCode_(en, value, shimString, helpString)          LOOKUP_STR_ARRAY_ENTRY_(libpath_ResultCode_##en),
# undef LIBPATH_DEFINING_STRING_ARRAY

#else

# define LIBPATH_DEFINE_ResultCode_(en, value, shimString, helpString)          libpath_ResultCode_##en value /*!< helpString */,

#endif

#if 0
LIBPATH_DEFINE_ResultCode_(Move, LIBPATH_NOTHING, Move, Move source file to destination)
LIBPATH_DEFINE_ResultCode_(MoveOrFallbackCopy, LIBPATH_NOTHING, MoveOrFallbackCopy, Move source file to destination or attempt copy if move fails)
LIBPATH_DEFINE_ResultCode_(HardLink, LIBPATH_NOTHING, HardLink, Make destination a hard-link to the source)
LIBPATH_DEFINE_ResultCode_(HardLinkOrFallbackCopy, LIBPATH_NOTHING, HardLinkOrFallbackCopy, Make destination a hard-link to the source or attempt copy if link fails)
#endif

#if !defined(LIBPATH_DEFINING_STRING_VARIABLES) && !defined(LIBPATH_DEFINING_STRING_ARRAY)
LIBPATH_DEFINE_ResultCode_(INVALID, =-1000000, INVALID, INVALID)
#endif

LIBPATH_DEFINE_ResultCode_(UnsupportedOperation, LIBPATH_NOTHING, UnsupportedOperation, operation is not supported)
LIBPATH_DEFINE_ResultCode_(UnexpectedCondition, LIBPATH_NOTHING, UnexpectedCondition, unexpected condition)
LIBPATH_DEFINE_ResultCode_(OutOfMemory, LIBPATH_NOTHING, OutOfMemory, out of memory)

LIBPATH_DEFINE_ResultCode_(NoPathSpecified, LIBPATH_NOTHING, NoPathSpecified, no path specified)
LIBPATH_DEFINE_ResultCode_(BadPathCharacter, LIBPATH_NOTHING, BadPathCharacter, bad path character)

LIBPATH_DEFINE_ResultCode_(OptionNotSupported, LIBPATH_NOTHING, OptionNotSupported, option not supported)
LIBPATH_DEFINE_ResultCode_(InvalidRoot, LIBPATH_NOTHING, InvalidRoot, invalid root)

LIBPATH_DEFINE_ResultCode_(ParameterIsReservedAndMustBeZero, LIBPATH_NOTHING, ParameterIsReservedAndMustBeZero, a reserved parameter that is reserved for future use must have the value 0 or NULL)

LIBPATH_DEFINE_ResultCode_(FirstPathInvalid, LIBPATH_NOTHING, FirstPathInvalid, first/only path parameter is invalid)
LIBPATH_DEFINE_ResultCode_(SecondPathInvalid, LIBPATH_NOTHING, SecondPathInvalid, second path parameter is invalid)
LIBPATH_DEFINE_ResultCode_(WorkingDirectoryPathInvalid, LIBPATH_NOTHING, WorkingDirectoryPathInvalid, working directory path parameter is invalid)

#if 0
LIBPATH_DEFINE_ResultCode_(UnhandledException, LIBPATH_NOTHING, UnhandledException, unhandled exception)
LIBPATH_DEFINE_ResultCode_(FileSystemOperationFailed, LIBPATH_NOTHING, FileSystemOperationFailed, the file-system operation used to carry out the action failed (OS-specific failure code stored in copy-info))

LIBPATH_DEFINE_ResultCode_(InvalidSourcePath, LIBPATH_NOTHING, InvalidSourcePath, invalid source path)
LIBPATH_DEFINE_ResultCode_(InvalidDestinationPath, LIBPATH_NOTHING, InvalidDestinationPath, invalid destination path)
LIBPATH_DEFINE_ResultCode_(SourceAndDestinationAreSame, LIBPATH_NOTHING, SourceAndDestinationAreSame, source and destination refer to same path)
LIBPATH_DEFINE_ResultCode_(SourceDoesNotExist, LIBPATH_NOTHING, SourceDoesNotExist, source does not exist)
LIBPATH_DEFINE_ResultCode_(InvalidSourceType, LIBPATH_NOTHING, InvalidSourceType, source is not a file)
LIBPATH_DEFINE_ResultCode_(InvalidDestinationType, LIBPATH_NOTHING, InvalidDestinationType, invalid destination file-system entry type)
LIBPATH_DEFINE_ResultCode_(DestinationExists, LIBPATH_NOTHING, DestinationExists, destination already exists)
LIBPATH_DEFINE_ResultCode_(DestinationDirectoryDoesNotExist, LIBPATH_NOTHING, DestinationDirectoryDoesNotExist, destination directory does not exist)


LIBPATH_DEFINE_ResultCode_(DestinationPathTooLong, LIBPATH_NOTHING, DestinationPathTooLong, Destination path too long)
LIBPATH_DEFINE_ResultCode_(CouldNotCreateDestinationDirectory, LIBPATH_NOTHING, CouldNotCreateDestinationDirectory, Could not create destination directory)
LIBPATH_DEFINE_ResultCode_(CouldNotAccessDestinationDirectory, LIBPATH_NOTHING, CouldNotAccessDestinationDirectory, Could not access destination directory)
LIBPATH_DEFINE_ResultCode_(CopyFailed, LIBPATH_NOTHING, CopyFailed, copy failed)
LIBPATH_DEFINE_ResultCode_(CouldNotReadSourceFile, LIBPATH_NOTHING, CouldNotReadSourceFile, could not read from source file)
LIBPATH_DEFINE_ResultCode_(CouldNotWriteDestinationFile, LIBPATH_NOTHING, CouldNotWriteDestinationFile, could not write to destination file)
#endif

LIBPATH_DEFINE_ResultCode_(Success, =0, Success, operation completed successfully)

#undef LIBPATH_DEFINE_ResultCode_


/* ///////////////////////////// end of file //////////////////////////// */


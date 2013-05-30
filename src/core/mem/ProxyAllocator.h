/*
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "Types.h"
#include "Memory.h"

namespace crown
{

class Allocator;

/// Offers the facility to tag allocations by a string identifier.
class ProxyAllocator
{
public:

	/// Tag all allocations made with @allocator by the given @name
					ProxyAllocator(const char* name, Allocator& allocator);

	/// @copydoc Allocator::allocate()
	void*			allocate(size_t size, size_t align = memory::DEFAULT_ALIGN);

	/// @copydoc Allocator::deallocate()
	void			deallocate(void* data);

	/// Returns the name of the proxy allocator
	const char*		name() const;

private:

	Allocator&		m_allocator;
	const char*		m_name;
};

} // namespace crown

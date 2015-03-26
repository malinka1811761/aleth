/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
/** @file TransientDirectory.cpp
 * @author Marek Kotewicz <marek@ethdev.com>
 * @date 2015
 */

#include <boost/filesystem.hpp>
#include <libdevcore/Exceptions.h>
#include "TransientDirectory.h"

using namespace std;
using namespace dev;
using namespace dev::test;

TransientDirectory::TransientDirectory(std::string const& _path) : m_path(_path)
{
	// we never ever want to delete a directory (including all its contents) that we did not create ourselves.
	if (boost::filesystem::exists(m_path))
		BOOST_THROW_EXCEPTION(FileError());

	boost::filesystem::create_directories(m_path);
}

TransientDirectory::~TransientDirectory()
{
	boost::filesystem::remove_all(m_path);
}

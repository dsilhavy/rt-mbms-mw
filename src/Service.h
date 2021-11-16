// 5G-MAG Reference Tools
// MBMS Middleware Process
//
// Copyright (C) 2021 Klaus Kühnhammer (Österreichische Rundfunksender GmbH & Co KG)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
// 
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

#include <string>
#include <thread>
#include <libconfig.h++>
#include "File.h"
#include "Receiver.h"
#include "ContentStream.h"

namespace MBMS_RT {
  class Service {
    public:
      Service();
      Service(const libconfig::Config& cfg, std::string tmgi, const std::string& mcast, unsigned long long tsi, std::string iface, boost::asio::io_service& io_service);
      virtual ~Service();

      void add_name(std::string name, std::string lang);

      void add_and_start_content_stream(std::shared_ptr<ContentStream> s) { _content_streams.push_back(s); s->start(); };

    private:
      std::vector<std::shared_ptr<ContentStream>> _content_streams;
  };
}

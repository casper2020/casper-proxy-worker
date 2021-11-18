/**
 * @file oauth2-client.h
 *
 * Copyright (c) 2011-2021 Cloudware S.A. All rights reserved.
 *
 * This file is part of casper-http-gateway.
 *
 * casper-http-gateway is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * casper-http-gateway  is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with casper-http-gateway.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#ifndef CASPER_HTTP_GATEWAY_OAUTH2_CLIENT_H_
#define CASPER_HTTP_GATEWAY_OAUTH2_CLIENT_H_

#include "casper/job/deferrable/base.h"
#include "casper/http/gateway/arguments.h"
#include "casper/http/gateway/deferred.h"

namespace casper
{

    namespace http
    {
    
        namespace gateway
        {
        
            enum class OAuth2ClientStep : uint8_t {
                Fetching = 5,
                DoingIt  = 95,
                Done     = 100
            };
                    
            // TODO: fix this                
        
            class OAuth2Client final : public ::casper::job::deferrable::Base<Arguments, OAuth2ClientStep, OAuth2ClientStep::Done>
            {
                                
            public: // Static Const Data
                
                constexpr static const char* const sk_tube_ = "gw-oauth2-http-client";
                
            public: // Constructor(s) / Destructor
                
                OAuth2Client () = delete;
                OAuth2Client (const ev::Loggable::Data& a_loggable_data, const cc::easy::job::Job::Config& a_config);
                virtual ~OAuth2Client ();

            protected: // Inherited Virtual Method(s) / Function(s) - ::casper::job::deferrable::Base<OAuth2ClientStep, OAuth2ClientStep::Done>
                
                virtual void InnerSetup ();
                virtual void InnerRun   (const int64_t& a_id, const Json::Value& a_payload, cc::easy::job::Job::Response& o_response);

            protected: // Method(s) / Function(s) - deferrable::Dispatcher Callbacks
                
                uint16_t OnDeferredRequestCompleted (const ::casper::job::deferrable::Deferred<gateway::Arguments>* a_deferred, Json::Value& o_payload);

            }; // end of class 'Base'
        
        } // end of namespace 'gateway'
    
    } // end of namespace 'http'

} // end of namespace 'casper'

#endif // CASPER_HTTP_GATEWAY_OAUTH2_CLIENT_H_

/******************************************************************************
* Copyright © 2013-2022 The Komodo Platform Developers.                      *
*                                                                            *
* See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
* the top-level directory of this distribution for the individual copyright  *
* holder information and the developer policies on copyright and licensing.  *
*                                                                            *
* Unless otherwise agreed in a custom licensing agreement, no part of the    *
* Komodo Platform software, including this file may be copied, modified,     *
* propagated or distributed except according to the terms contained in the   *
* LICENSE file                                                               *
*                                                                            *
* Removal or modification of this copyright notice is prohibited.            *
*                                                                            *
******************************************************************************/

#pragma once

#include <type_traits>

#include <nlohmann/json_fwd.hpp> //> nlohmann::json

#include "../api.call.hpp"

namespace mm2::api
{

}

namespace atomic_dex::mm2
{
    template <typename Rpc>
    concept rpc = requires(Rpc rpc)
    {
        atomic_dex::api_call<Rpc> && Rpc::is_v2 && std::is_same_v<decltype(Rpc::is_v2), bool>;
    };

    struct rpc_basic_error_type
    {
        std::string error;
        std::string error_path;
        std::string error_trace;
        std::string error_type;
        std::string error_data;
    };

    inline void from_json(const nlohmann::json& j, rpc_basic_error_type& in);
}

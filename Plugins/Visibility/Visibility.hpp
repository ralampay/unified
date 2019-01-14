#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <set>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Visibility {

class Visibility : public NWNXLib::Plugin
{
public:
    Visibility(const Plugin::CreateParams& params);
    virtual ~Visibility();

private:

    static int32_t TestObjectVisibleHook(NWNXLib::API::CNWSMessage *pThis, NWNXLib::API::CNWSObject *pAreaObject, NWNXLib::API::CNWSObject *pPlayerGameObject);
    NWNXLib::Hooking::FunctionHook* m_TestObjectVisibilityHook;
    std::set<NWNXLib::API::Types::ObjectID> m_GlobalVisibilityOverrideSet;

    static bool GetGlobalOverride(NWNXLib::API::Types::ObjectID targetId);
    static int32_t GetPersonalOverride(NWNXLib::API::Types::ObjectID playerId, NWNXLib::API::Types::ObjectID targetId); 

    ArgumentStack GetVisibilityOverride (ArgumentStack&& args);
    ArgumentStack SetVisibilityOverride (ArgumentStack&& args); 
};

}

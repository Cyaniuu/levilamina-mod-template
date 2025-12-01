#include "mod/MyMod.h"
#include <ll/api/event/EventBus.h>
#include <ll/api/event/player/PlayerJoinEvent.h>
#include <ll/api/mod/RegisterHelper.h>
#include <mc/nbt/CompoundTagVariant.h>
#include <mc/safety/RedactableString.h>
#include <mc/world/actor/player/Inventory.h>
#include <mc/world/actor/player/PlayerInventory.h>
#include <mc/world/item/ItemLockHelper.h>
#include <mc/world/item/ItemLockMode.h>
#include <mc/world/item/ItemStack.h>
#include <mc/world/item/VanillaItemNames.h>

namespace my_mod {

MyMod& MyMod::getInstance() {
    static MyMod instance;
    return instance;
}

bool MyMod::load() {
    getSelf().getLogger().info("已加载");
    return true;
}

bool MyMod::enable() {
    mListener = ll::event::EventBus::getInstance().emplaceListener<ll::event::PlayerJoinEvent>(
        [](ll::event::PlayerJoinEvent& event) {
            auto item = ItemStack(VanillaItemNames::Diamond());

            auto name = Bedrock::Safety::RedactableString();
            name.set("§r§b新手礼包§r");
            item.setCustomName(name);

            event.self().addAndRefresh(item);
            event.self().sendMessage("§b给你一个新手礼包~");
            // 子沐老师 好像背包满了就没有新手礼包了(不过好像新手的背包也不会满)qwq 而且每次进入都会得到一个新手礼包~
        }
    );
    getSelf().getLogger().info("已启用");
    return true;
}

bool MyMod::disable() {
    getSelf().getLogger().info("已禁用");
    ll::event::EventBus::getInstance().removeListener(mListener);
    return true;
}

bool MyMod::unload() {
    getSelf().getLogger().info("已卸载");
    return true;
}

} // namespace my_mod

LL_REGISTER_MOD(my_mod::MyMod, my_mod::MyMod::getInstance());

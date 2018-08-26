#pragma once
#include "ui_menu.hpp"

namespace elona
{
namespace ui
{

class ui_menu_town_economy : public ui_menu<dummy_result>
{
public:
    ui_menu_town_economy()
    {
    }

protected:
    virtual bool init();
    virtual void update();
    virtual void draw();
    virtual optional<ui_menu_town_economy::result_type> on_key(
        const std::string& key);

private:
    int _city;
};

} // namespace ui
} // namespace elona

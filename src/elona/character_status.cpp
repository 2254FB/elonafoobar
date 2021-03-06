#include "character_status.hpp"

#include <limits>

#include "ability.hpp"
#include "adventurer.hpp"
#include "animation.hpp"
#include "chara_db.hpp"
#include "character.hpp"
#include "config.hpp"
#include "fov.hpp"
#include "i18n.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "message.hpp"
#include "random.hpp"
#include "trait.hpp"
#include "variables.hpp"



namespace elona
{

namespace
{

int get_random_body_part()
{
    if (rnd(7) == 0)
    {
        return 2;
    }
    if (rnd(9) == 0)
    {
        return 3;
    }
    if (rnd(8) == 0)
    {
        return 5;
    }
    if (rnd(4) == 0)
    {
        return 6;
    }
    if (rnd(6) == 0)
    {
        return 7;
    }
    if (rnd(5) == 0)
    {
        return 8;
    }
    if (rnd(5) == 0)
    {
        return 9;
    }
    return 1;
}

} // namespace



void modify_ether_disease_stage(int delta)
{
    int original_amount = 0;
    int add_amount = 0;
    int mod_amount = 0;
    int cnt2_at_m134 = 0;
    int i_at_m134 = 0;
    original_amount = game_data.ether_disease_stage / 1000;
    add_amount = delta + (delta > 0) * game_data.ether_disease_speed;
    if (trait(168))
    {
        if (delta > 0)
        {
            add_amount = add_amount * 100 / 150;
        }
    }
    game_data.ether_disease_stage =
        clamp(game_data.ether_disease_stage + add_amount, 0, 20000);
    mod_amount = game_data.ether_disease_stage / 1000 - original_amount;
    if (mod_amount > 0)
    {
        if (original_amount == 0)
        {
            txt(i18n::s.get("core.chara.corruption.symptom"),
                Message::color{ColorIndex::purple});
            maybe_show_ex_help(15);
        }
        if (original_amount + mod_amount >= 20)
        {
            add_amount = 20 - original_amount;
        }
        else
        {
            add_amount = mod_amount;
        }
        for (int cnt = 0, cnt_end = (add_amount); cnt < cnt_end; ++cnt)
        {
            cnt2_at_m134 = cnt;
            if (original_amount + cnt2_at_m134 > 20)
            {
                break;
            }
            for (int cnt = 0; cnt < 100000; ++cnt)
            {
                int tid = rnd(17) + 200;
                int stat = trait_get_info(0, tid);
                if (stat == 0 || traitref != 3)
                {
                    continue;
                }
                if (trait(tid) <= traitref(1))
                {
                    continue;
                }
                --trait(tid);
                i_at_m134 = original_amount + cnt2_at_m134;
                game_data.ether_disease_history.at(i_at_m134) = tid;
                txt(i18n::s.get("core.chara.corruption.add"),
                    Message::color{ColorIndex::purple});
                txt(traitrefn(1), Message::color{ColorIndex::red});
                if (tid == 203)
                {
                    body = 9;
                    lost_body_part(0);
                }
                if (tid == 205)
                {
                    body = 3;
                    lost_body_part(0);
                }
                if (tid == 206)
                {
                    body = 2;
                    lost_body_part(0);
                }
                break;
            }
        }
        animeload(8, cdata.player());
        chara_refresh(cdata.player());
        return;
    }
    if (mod_amount < 0)
    {
        if (original_amount + mod_amount < 0)
        {
            add_amount = original_amount;
        }
        else
        {
            add_amount = std::abs(mod_amount);
        }
        if (add_amount < 0)
        {
            add_amount = 0;
        }
        for (int cnt = 0, cnt_end = (add_amount); cnt < cnt_end; ++cnt)
        {
            cnt2_at_m134 = cnt;
            for (int cnt = 0; cnt < 100000; ++cnt)
            {
                int tid = rnd(17) + 200;
                if (cnt == 0)
                {
                    i_at_m134 = original_amount - cnt2_at_m134 - 1;
                    if (game_data.ether_disease_history.at(i_at_m134) != 0)
                    {
                        tid = game_data.ether_disease_history.at(i_at_m134);
                    }
                }
                int stat = trait_get_info(0, tid);
                if (stat == 0 || traitref != 3)
                {
                    continue;
                }
                if (trait(tid) >= 0)
                {
                    continue;
                }
                ++trait(tid);
                txt(i18n::s.get("core.chara.corruption.remove"),
                    Message::color{ColorIndex::green});
                txt(traitrefn(0), Message::color{ColorIndex::green});
                break;
            }
        }
        animeload(10, cdata.player());
        chara_refresh(cdata.player());
        return;
    }
}



void modify_potential(Character& chara, int id, int delta)
{
    sdata.get(id, chara.index).potential =
        clamp(sdata.get(id, chara.index).potential + delta, 2, 400);
}



void modify_karma(Character& chara, int delta)
{
    if (trait(162) && delta < 0)
    {
        delta = delta * 75 / 100;
        if (delta == 0)
            return;
    }
    if (trait(169) && delta < 0)
    {
        delta = delta * 150 / 100;
    }

    if (delta >= 0)
    {
        Message::instance().txtef(ColorIndex::orange);
    }
    else
    {
        Message::instance().txtef(ColorIndex::purple);
    }
    txt(i18n::s.get("core.chara_status.karma.changed", delta));
    if (delta > 0)
    {
        if (chara.karma < -30 && chara.karma + delta >= -30)
        {
            txt(i18n::s.get(
                    "core.chara_status.karma.you_are_no_longer_criminal"),
                Message::color{ColorIndex::green});
        }
    }
    else if (delta < 0)
    {
        if (chara.karma >= -30 && chara.karma + delta < -30)
        {
            txt(i18n::s.get("core.chara_status.karma.you_are_criminal_now"),
                Message::color{ColorIndex::purple});
            go_hostile();
        }
    }

    chara.karma += delta;

    int max = 20;
    if (trait(162))
    {
        max -= 20;
    }
    if (trait(169))
    {
        max += 20;
    }
    chara.karma = clamp(chara.karma, -100, max);
}



void modify_weight(Character& chara, int delta, bool force)
{
    int min = chara.height * chara.height * 18 / 25000;
    int max = chara.height * chara.height * 24 / 10000;

    if (chara.weight < min)
    {
        chara.weight = min;
        return;
    }
    if (!force && delta > 0)
    {
        if (chara.weight > max)
        {
            return;
        }
    }

    chara.weight =
        chara.weight * (100 + delta) / 100 + (delta > 0) - (delta < 0);

    if (chara.weight < 1)
    {
        chara.weight = 1;
    }
    if (is_in_fov(chara))
    {
        if (delta >= 3)
        {
            txt(i18n::s.get("core.chara.weight.gain", chara));
        }
        if (delta <= -3)
        {
            txt(i18n::s.get("core.chara.weight.lose", chara));
        }
    }
}



void modify_height(Character& chara, int delta)
{
    chara.height =
        chara.height * (100 + delta) / 100 + (delta > 0) - (delta < 0);
    if (chara.height < 1)
    {
        chara.height = 1;
    }
    if (is_in_fov(chara))
    {
        if (delta > 0)
        {
            txt(i18n::s.get("core.chara.height.gain", chara));
        }
        if (delta < 0)
        {
            txt(i18n::s.get("core.chara.height.lose", chara));
        }
    }
}



void refresh_speed(Character& chara)
{
    chara.current_speed = sdata(18, chara.index) *
        clamp((100 - chara.speed_correction_value), 0, 100) / 100;
    if (chara.current_speed < 10)
    {
        chara.current_speed = 10;
    }
    chara.speed_percentage_in_next_turn = 0;

    if (chara.index != 0 && game_data.mount != chara.index)
        return;

    if (game_data.mount != 0)
    {
        const auto mount_speed = sdata(18, game_data.mount) *
            clamp(100 - cdata[game_data.mount].speed_correction_value, 0, 100) /
            100;

        cdata.player().current_speed = mount_speed * 100 /
            clamp(100 + mount_speed - sdata(10, game_data.mount) * 3 / 2 -
                      sdata(301, 0) * 2 -
                      (cdata[game_data.mount].is_suitable_for_mount() == 1) *
                          50,
                  100,
                  1000);
        if (cdata[game_data.mount].is_unsuitable_for_mount())
        {
            cdata.player().current_speed /= 10;
        }
        if (game_data.mount == chara.index)
        {
            chara.current_speed =
                clamp(sdata(10, chara.index) + sdata(301, 0), 10, mount_speed);
            return;
        }
    }

    gspdorg = sdata.get(18, 0).original_level;

    if (game_data.mount == 0)
    {
        int n = cdata.player().nutrition / 1000 * 1000;
        if (n < 1000)
        {
            cdata.player().speed_percentage_in_next_turn -= 30;
        }
        if (n < 2000)
        {
            cdata.player().speed_percentage_in_next_turn -= 10;
        }
        if (cdata.player().sp < 0)
        {
            cdata.player().speed_percentage_in_next_turn -= 30;
        }
        if (cdata.player().sp < 25)
        {
            cdata.player().speed_percentage_in_next_turn -= 20;
        }
        if (cdata.player().sp < 50)
        {
            cdata.player().speed_percentage_in_next_turn -= 10;
        }
    }
    if (cdata.player().inventory_weight_type >= 3)
    {
        cdata.player().speed_percentage_in_next_turn -= 50;
    }
    if (cdata.player().inventory_weight_type == 2)
    {
        cdata.player().speed_percentage_in_next_turn -= 30;
    }
    if (cdata.player().inventory_weight_type == 1)
    {
        cdata.player().speed_percentage_in_next_turn -= 10;
    }
    if (map_data.type == mdata_t::MapType::world_map ||
        map_data.type == mdata_t::MapType::field)
    {
        if (game_data.cargo_weight > game_data.current_cart_limit)
        {
            cdata.player().speed_percentage_in_next_turn -= 25 +
                25 *
                    (game_data.cargo_weight /
                     (game_data.current_cart_limit + 1));
        }
    }
    gspd = cdata.player().current_speed *
        (100 + cdata.player().speed_percentage) / 100;
    if (gspd < 10)
    {
        gspd = 10;
    }
}



void refresh_speed_correction_value(Character& chara)
{
    int number_of_body_parts{};
    for (const auto& equipment_slot : chara.equipment_slots)
    {
        if (equipment_slot)
        {
            ++number_of_body_parts;
        }
    }
    if (number_of_body_parts > 13)
    {
        chara.speed_correction_value = (number_of_body_parts - 13) * 5;
    }
    else
    {
        chara.speed_correction_value = 0;
    }
}



void gain_new_body_part(Character& chara)
{
    int slot = -1;
    for (size_t i = 0; i < chara.equipment_slots.size(); ++i)
    {
        if (!chara.equipment_slots[i])
        {
            slot = static_cast<int>(i);
            break;
        }
    }

    if (slot == -1)
    {
        refresh_speed_correction_value(chara);
        return;
    }

    const auto body_part = get_random_body_part();
    chara.equipment_slots[slot] = EquipmentSlot{body_part, ItemRef::null()};
    if (!cm)
    {
        txt(i18n::s.get(
            "core.chara_status.gain_new_body_part",
            chara,
            i18n::s.get_enum("core.ui.body_part", body_part)));
    }

    refresh_speed_correction_value(chara);
}



void gain_level(Character& chara)
{
    chara.experience -= chara.required_experience;
    if (chara.experience < 0)
    {
        chara.experience = 0;
    }
    ++chara.level;
    if (chara.role != Role::adventurer)
    {
        if (r2 == 0)
        {
            if (chara.index == 0)
            {
                txt(i18n::s.get(
                        "core.chara.gain_level.self", chara, chara.level),
                    Message::color{ColorIndex::green});
            }
            else
            {
                txt(i18n::s.get("core.chara.gain_level.other", chara),
                    Message::color{ColorIndex::green});
            }
        }
    }
    else
    {
        addnews(2, chara.index);
    }
    p = 5 * (100 + sdata.get(14, chara.index).original_level * 10) /
            (300 + chara.level * 15) +
        1;
    if (chara.index == 0)
    {
        if (chara.level % 5 == 0)
        {
            if (chara.max_level < chara.level)
            {
                if (chara.level <= 50)
                {
                    ++game_data.acquirable_feat_count;
                }
            }
        }
        gain_special_action();
        p += trait(154);
    }
    chara.skill_bonus += p;
    chara.total_skill_bonus += p;
    if (cdatan(2, chara.index) == u8"core.mutant"s ||
        (chara.index == 0 && trait(0) == 1))
    {
        if (chara.level < 37)
        {
            if (chara.level % 3 == 0)
            {
                if (chara.max_level < chara.level)
                {
                    gain_new_body_part(chara);
                }
            }
        }
    }
    if (chara.max_level < chara.level)
    {
        chara.max_level = chara.level;
    }
    if (chara.index >= 16)
    {
        grow_primary_skills(chara);
    }
    update_required_experience(chara);
    chara_refresh(chara);
}



void grow_primary_skills(Character& chara)
{
    for (int i = 10; i < 20; ++i)
    {
        sdata.get(i, chara.index).original_level += rnd(3);
        if (sdata.get(i, chara.index).original_level > 2000)
        {
            sdata.get(i, chara.index).original_level = 2000;
        }
    }
    for (const auto& skill : mainskill)
    {
        sdata.get(skill, chara.index).original_level += rnd(3);
        if (sdata.get(skill, chara.index).original_level > 2000)
        {
            sdata.get(skill, chara.index).original_level = 2000;
        }
    }
}



void update_required_experience(Character& chara)
{
    chara.required_experience = clamp(chara.level, 1, 200) *
            (clamp(chara.level, 1, 200) + 1) *
            (clamp(chara.level, 1, 200) + 2) *
            (clamp(chara.level, 1, 200) + 3) +
        3000;
    if (chara.required_experience > 100000000 || chara.required_experience < 0)
    {
        chara.required_experience = 100000000;
    }
}



void earn_gold(Character& chara, int delta)
{
    constexpr auto max = std::numeric_limits<decltype(chara.gold)>::max();

    if (chara.gold > max - delta)
    {
        chara.gold = max;
    }
    else
    {
        chara.gold += delta;
    }
}



void earn_platinum(Character& chara, int delta)
{
    constexpr auto max =
        std::numeric_limits<decltype(chara.platinum_coin)>::max();

    if (chara.platinum_coin > max - delta)
    {
        chara.platinum_coin = max;
    }
    else
    {
        chara.platinum_coin += delta;
    }
}



int gain_skills_by_geen_engineering(
    const Character& original_ally,
    const Character& gene_ally)
{
    if (gene_ally.splits() || gene_ally.splits2())
    {
        return 0;
    }
    randomize(charaid2int(gene_ally.id));
    int dbmax = 0;
    for (int cnt = 0; cnt < 100; ++cnt)
    {
        rtval = rnd(40) + 150;
        if (sdata(rtval, original_ally.index) == 0)
        {
            if (sdata(rtval, gene_ally.index) > 0)
            {
                dblist(0, dbmax) = rtval;
                ++dbmax;
            }
        }
    }
    rtval(0) = dblist(0, 0);
    rtval(1) = -1;
    if (dbmax >= 2)
    {
        if (rnd(3) == 0)
        {
            for (int cnt = 1, cnt_end = cnt + (dbmax - 1); cnt < cnt_end; ++cnt)
            {
                if (dblist(0, cnt) != rtval)
                {
                    rtval(1) = dblist(0, cnt);
                    break;
                }
            }
        }
    }
    randomize();
    return dbmax;
}



int transplant_body_parts(
    const Character& original_ally,
    const Character& gene_ally)
{
    int dbmax = 0;
    s(1) = chara_db_get_filter(gene_ally.id);
    if (strutil::contains(s(1), u8"/man/"))
    {
        return -1;
    }
    if (gene_ally.splits() || gene_ally.splits2())
    {
        return -1;
    }
    rtval(1) = -1;
    for (size_t i = 0; i < original_ally.equipment_slots.size(); ++i)
    {
        if (!original_ally.equipment_slots[i])
        {
            rtval(1) = i + 100;
        }
    }
    if (rtval(1) == -1)
    {
        return -1;
    }
    for (size_t cnt = 0; cnt < gene_ally.equipment_slots.size(); ++cnt)
    {
        f = gene_ally.equipment_slots[cnt].type;
        if (f == 11 || f == 10 || f == 4)
        {
            continue;
        }
        if (f != 0)
        {
            dblist(0, dbmax) = f;
            ++dbmax;
        }
    }
    if (dbmax == 0)
    {
        return -1;
    }
    randomize(charaid2int(gene_ally.id));
    for (int cnt = 0; cnt < 3; ++cnt)
    {
        rtval = dblist(0, rnd(dbmax));
        f = 0;
        for (size_t i = 0; i < original_ally.equipment_slots.size(); ++i)
        {
            if (!original_ally.equipment_slots[i])
            {
                continue;
            }
            if (original_ally.equipment_slots[i].type == rtval)
            {
                f = 1;
            }
        }
        if (f)
        {
            break;
        }
    }
    if (f == 0)
    {
        randomize();
        return rtval(1);
    }
    DIM3(dblist, 2, 800);
    for (int i = 0; i < 30; ++i)
    {
        ++dblist(0, gene_ally.equipment_slots[i].type);
    }
    for (int cnt = 0; cnt < 25; ++cnt)
    {
        rtval = rnd(15) + 1;
        f = 0;
        for (int i = 0; i < 30; ++i)
        {
            if (original_ally.equipment_slots[i].type == rtval)
            {
                ++f;
            }
        }
        if (f < dblist(0, rtval))
        {
            f = -1;
            break;
        }
    }
    randomize();
    if (f == -1)
    {
        return rtval(1);
    }
    else
    {
        return -1;
    }
}

} // namespace elona

#include "elona.hpp"
#include "variables.hpp"


namespace elona
{
void label_2743(bool = true);
void cs_list(
    int CNT,
    const std::string& prm_543,
    int prm_544 = 0,
    int prm_545 = 0,
    int prm_546 = 0,
    int prm_547 = 0,
    int prm_548 = 0,
    int prm_549 = 0);


int label_20592()
{
label_20591:
    if (invctrl == 22)
    {
        if (invctrl(1) == 1)
        {
            label_2087();
        }
    }
    if (menucycle == 1)
    {
        if (mdata(6) == 1)
        {
            p = 0;
            {
                int cnt = 0;
                for (int cnt_end = cnt + (12); cnt < cnt_end; ++cnt)
                {
                    if (cycle(cnt, 1) == -1)
                    {
                        break;
                    }
                    if (cycle(cnt, 1) == invctrl)
                    {
                        p = 1;
                        break;
                    }
                }
            }
            if (p == 0)
            {
                invctrl = cycle(0, 1);
            }
        }
    }
    invmark(11) = 0;
    invmark(12) = 0;
    page = 0;
    pagesize = 16;
    listmax = 0;
    cs = invmark(invctrl) % 1000;
    page = invmark(invctrl) / 1000;
    cs_bk = -1;
    cc = 0;
    page_load();
    mainweapon = -1;
    {
        int cnt = 0;
        for (int cnt_end = cnt + (2); cnt < cnt_end; ++cnt)
        {
            if (cnt == 0)
            {
                p = -1;
                if (invctrl == 2 || invctrl == 6 || invctrl == 10
                    || invctrl == 12 || invctrl == 16 || invctrl == 20
                    || invctrl == 21 || invctrl == 23 || invctrl == 24
                    || invctrl == 25)
                {
                    continue;
                }
            }
            if (cnt == 1)
            {
                p = cc;
                if (invctrl == 20 || invctrl == 25)
                {
                    p = tc;
                }
                if (invctrl == 27)
                {
                    p = map(tlocx, tlocy, 1) - 1;
                    if (p == 0 || p == -1)
                    {
                        continue;
                    }
                }
                if (invctrl == 3 || invctrl == 11 || invctrl == 22
                    || invctrl == 28)
                {
                    break;
                }
            }
            inv_getheader(p);
            cnt2 = cnt;
            if (invctrl != 1 && invctrl != 5 && invctrl != 13 && invctrl != 14
                && invctrl != 18 && invctrl != 20 && invctrl != 23
                && invctrl != 25 && invctrl != 27)
            {
                countequip = 0;
            }
            else
            {
                countequip = 1;
            }
            if (invctrl == 11 || invctrl == 12 || invctrl == 25
                || invctrl == 27)
            {
                showmoney = 1;
            }
            else
            {
                showmoney = 0;
            }
            {
                int cnt = invhead;
                for (int cnt_end = cnt + (invrange); cnt < cnt_end; ++cnt)
                {
                    if (inv_number(cnt) <= 0)
                    {
                        inv_number(cnt) = 0;
                        continue;
                    }
                    if (inv_id(cnt) == 488)
                    {
                        inv_function(cnt) = 9;
                    }
                    if (inv_id(cnt) == 504)
                    {
                        inv_function(cnt) = 38;
                    }
                    if (inv_id(cnt) >= 800 || inv_id(cnt) < 0)
                    {
                        dialog(
                            u8"Invalid Item Id found. Item No:"s + cnt
                            + u8", Id:"s + inv_id(cnt)
                            + u8" has been removed from your inventory."s);
                        inv_number(cnt) = 0;
                        inv_id(cnt) = 0;
                        continue;
                    }
                    if (mdata(6) == 1)
                    {
                        if (invctrl == 7)
                        {
                            if (refitem(inv_id(cnt), 9) != 53100
                                && inv_id(cnt) != 621)
                            {
                                continue;
                            }
                        }
                    }
                    if (cnt2 == 0)
                    {
                        if (invctrl == 27)
                        {
                            if (inv_x(cnt) != tlocx || inv_y(cnt) != tlocy)
                            {
                                continue;
                            }
                        }
                        else
                        {
                            if (invctrl != 11 && invctrl != 22 && invctrl != 28)
                            {
                                if (inv_x(cnt) != cdata_x(cc)
                                    || inv_y(cnt) != cdata_y(cc))
                                {
                                    continue;
                                }
                            }
                        }
                    }
                    item_checkknown(cnt);
                    reftype = refitem(inv_id(cnt), 5);
                    if (inv_own_state(cnt) == 5)
                    {
                        if (ibit(16, cnt) == 0 || invctrl != 14)
                        {
                            if (invctrl != 1)
                            {
                                continue;
                            }
                        }
                    }
                    if (countequip == 0)
                    {
                        if (inv_body_part(cnt) != 0)
                        {
                            continue;
                        }
                    }
                    if (inv_body_part(cnt) != 0)
                    {
                        if (mainweapon == -1)
                        {
                            if (reftype == 10000)
                            {
                                mainweapon = cnt;
                            }
                        }
                    }
                    if (invctrl == 5)
                    {
                        if (reftype != 57000 && reftype != 91000
                            && inv_material(cnt) != 35)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 6)
                    {
                        if (iequiploc(cnt) != cdata(body, cc) / 10000)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 7)
                    {
                        if (refitem(inv_id(cnt), 2) == 0)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 8)
                    {
                        if (refitem(inv_id(cnt), 4) == 0)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 9)
                    {
                        if (refitem(inv_id(cnt), 3) == 0)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 11)
                    {
                        if (inv_id(cnt) == 54 || inv_id(cnt) == 55)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 11 || invctrl == 12)
                    {
                        if (shoptrade)
                        {
                            if (inv_weight(cnt) >= 0)
                            {
                                continue;
                            }
                            else
                            {
                                if (reftype != 92000)
                                {
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            if (inv_weight(cnt) < 0)
                            {
                                if (reftype == 92000)
                                {
                                    continue;
                                }
                            }
                        }
                        if (inv_value(cnt) <= 1)
                        {
                            continue;
                        }
                        if (ibit(5, cnt) == 1)
                        {
                            continue;
                        }
                        if (inv_param3(cnt) < 0)
                        {
                            continue;
                        }
                        if (inv_quality(cnt) == 6)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 13)
                    {
                        if (inv_identification_state(cnt) >= 3)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 14)
                    {
                        if (inv_function(cnt) == 0
                            && refitem(inv_id(cnt), 11) == 0
                            && ibit(10, cnt) == 0)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 15)
                    {
                        if (reftype != 72000)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 16)
                    {
                        if (reftype != 57000)
                        {
                            continue;
                        }
                        else
                        {
                            if (inv_param2(cnt) != 0)
                            {
                                continue;
                            }
                        }
                    }
                    if (invctrl == 17)
                    {
                        if (reftype != 52000 && inv_id(cnt) != 617)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 18)
                    {
                        if (inv_id(cidip) == 617)
                        {
                            if (inv_id(cnt) != 342)
                            {
                                continue;
                            }
                        }
                        if (cidip == cnt || inv_id(cnt) == 516)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 19)
                    {
                        if (refitem(inv_id(cnt), 12) == 0)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 20)
                    {
                        if (inv_id(cnt) == 54 || inv_id(cnt) == 55)
                        {
                            continue;
                        }
                    }
                    if (invctrl == 21)
                    {
                        if (calcitemvalue(cnt, 0) * inv_number(cnt)
                            < calcitemvalue(citrade, 0) * inv_number(citrade)
                                / 2 * 3)
                        {
                            continue;
                        }
                        if (ibit(9, cnt))
                        {
                            continue;
                        }
                    }
                    if (invctrl == 23)
                    {
                        if (invctrl(1) == 0)
                        {
                            if (reftype >= 50000 && reftype != 60000)
                            {
                                continue;
                            }
                        }
                        if (invctrl(1) == 1)
                        {
                            if (reftype != 10000 && reftype != 24000)
                            {
                                continue;
                            }
                        }
                        if (invctrl(1) == 2)
                        {
                            if (reftype < 12000 || reftype >= 24000)
                            {
                                if (reftype < 30000 || reftype >= 50000)
                                {
                                    continue;
                                }
                            }
                        }
                        if (invctrl(1) == 3)
                        {
                            if (ibit(4, cnt) == 0)
                            {
                                continue;
                            }
                        }
                        if (invctrl(1) == 4)
                        {
                            if (inv_body_part(cnt) != 0)
                            {
                                continue;
                            }
                        }
                        if (invctrl(1) == 5)
                        {
                            if (reftype != 56000)
                            {
                                continue;
                            }
                        }
                        if (invctrl(1) == 6)
                        {
                            if (inv_weight(cnt) <= 0 || inv_id(cnt) == 641)
                            {
                                continue;
                            }
                        }
                        if (invctrl(1) == 7)
                        {
                            if (inv_quality(cnt) >= 4 || reftype >= 50000)
                            {
                                continue;
                            }
                        }
                    }
                    if (invctrl == 24)
                    {
                        if (invctrl(1) == 0)
                        {
                            if (gdata(20) == 36)
                            {
                                if (inv_id(cnt) != 687 || inv_param2(cnt) == 0)
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                if (inv_own_state(cnt) != 4)
                                {
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            if (inv_own_state(cnt) == 4)
                            {
                                continue;
                            }
                        }
                        if (invctrl(1) == 2)
                        {
                            if (inv_id(cnt) != 615)
                            {
                                continue;
                            }
                        }
                        if (reftype == 72000)
                        {
                            continue;
                        }
                        if (invctrl(1) == 3)
                        {
                            if (reftype != 57000)
                            {
                                continue;
                            }
                        }
                    }
                    else
                    {
                        if (inv_own_state(cnt) == 4)
                        {
                            if (invctrl != 1 && invctrl != 2 && invctrl != 3
                                && invctrl != 5)
                            {
                                continue;
                            }
                        }
                    }
                    if (invctrl == 26)
                    {
                        if (reftype != 52000 && inv_id(cnt) != 578
                            && inv_id(cnt) != 685 && inv_id(cnt) != 699
                            && inv_id(cnt) != 772)
                        {
                            continue;
                        }
                        if (inv_id(cnt) == 685)
                        {
                            if (inv_subname(cnt) != 0)
                            {
                                continue;
                            }
                        }
                    }
                    if (invctrl == 27)
                    {
                        if (cnt2 == 0)
                        {
                            if (inv_own_state(cnt) != 1)
                            {
                                continue;
                            }
                        }
                    }
                    list(0, listmax) = cnt;
                    list(1, listmax) = reftype * 1000 + inv_id(cnt);
                    if (inv_id(cnt) == 544)
                    {
                        list(1, listmax) += inv_param1(cnt) + 900;
                    }
                    else
                    {
                    }
                    if (invctrl == 1 || invctrl == 13)
                    {
                        if (inv_body_part(cnt) != 0)
                        {
                            list(1, listmax) -= 99999000;
                        }
                    }
                    if (cnt2 == 0)
                    {
                        list(1, listmax) -= 199998000;
                    }
                    if (invctrl == 28)
                    {
                        list(1, listmax) = calcmedalvalue(cnt);
                    }
                    ++listmax;
                }
            }
        }
    }
    f = 0;
    if (listmax == 0)
    {
        if (invctrl == 21)
        {
            txt(lang(
                itemname(citrade) + u8"に見合う物を所持していない。"s,
                u8"You don't have stuff that match "s + itemname(citrade)
                    + u8"."s));
            f = 1;
        }
        if (invctrl == 27)
        {
            if (tc != 0)
            {
                txt(lang(
                    name(tc) + u8"は盗めるものを所持していない。"s,
                    name(tc) + u8" has nothing to steal."s));
                f = 1;
            }
            else
            {
                txt(lang(
                    u8"そこに盗めるものはない。"s,
                    u8"There's nothing to steal."s));
                f = 1;
            }
        }
    }
    if (invctrl == 19)
    {
        int stat = item_find(60002, 2);
        if (stat == -1)
        {
            ++msgdup;
            txt(lang(u8"ここには祭壇がない。"s, u8"There's no altar here."s));
            f = 1;
        }
    }
    if (invctrl == 27)
    {
        if (tc > 0)
        {
            if (cdata_relationship(tc) == 10)
            {
                txt(lang(
                    u8"仲間からは盗みたくない。"s,
                    u8"You don't want to rob your ally."s));
                f = 1;
            }
        }
    }
    if (invctrl == 24)
    {
        if (invctrl(1) == 0)
        {
            if (gdata(20) == 36)
            {
                if (gdata(266) <= 0)
                {
                    txt(lang(
                        u8"現在魔術士ギルドのノルマはない。"s,
                        u8"You have no quota for Mages Guild."s));
                    f = 1;
                }
            }
        }
    }
    if (f == 1)
    {
        if (invsubroutine == 1)
        {
            invsubroutine = 0;
            return 0;
        }
        label_1419();
        label_2743(false);
    }
    label_2056();
    if (invctrl == 3)
    {
        if (listmax == 0)
        {
            label_2742();
            return 0;
        }
    }
    if (returnfromidentify == 0)
    {
        if (invctrl == 18)
        {
            valn = itemname(cidip, 1);
        }
        else
        {
            if (invctrl == 21)
            {
                valn = itemname(citrade);
            }
        }
        s(0) = "";
        s(1) = lang(u8"どのアイテムを調べる？ "s, u8"Examine what? "s);
        s(2) = lang(u8"どのアイテムを置く？ "s, u8"Drop what? "s);
        s(3) = lang(
            u8"どのアイテムを拾う？ "s,
            u8"Which item do you want to pick up? "s);
        s(4) = lang(u8"何を装備する？"s, u8"Equip what?"s);
        s(5) = lang(u8"何を食べよう？ "s, u8"Eat what? "s);
        s(6) = "";
        s(7) = lang(u8"どれを読む？ "s, u8"Read what? "s);
        s(8) = lang(u8"どれを飲む？ "s, u8"Drink what? "s);
        s(9) = lang(u8"どれを振る？ "s, u8"Zap what? "s);
        s(10) = lang(u8"どれを渡す？ "s, u8"Which item do you want to give? "s);
        s(11) = lang(u8"どれを購入する？ "s, u8"What do you want to buy? "s);
        s(12) = lang(u8"どれを売却する？ "s, u8"What do you want to sell? "s);
        s(13) = lang(
            u8"どのアイテムを鑑定する？ "s,
            u8"Which item do you want to identify? "s);
        s(14) = lang(u8"どのアイテムを使用する？ "s, u8"Use what? "s);
        s(15) = lang(u8"どれを開ける？ "s, u8"Open what? "s);
        s(16) = lang(u8"何を料理する？ "s, u8"Cook what? "s);
        s(17) = lang(u8"何を混ぜる？ "s, u8"Blend what? "s);
        s(18) = lang(
            u8"何に混ぜる？("s + valn + u8"の効果を適用するアイテムを選択) "s,
            u8"Which item do you want to apply the effect of "s + valn
                + u8"? "s);
        s(19) = lang(
            u8"何を神に捧げる？ "s,
            u8"What do you want to offer to your God? "s);
        s(20) =
            lang(u8"何を交換する？ "s, u8"Which item do you want to trade? "s);
        s(21) = lang(
            valn + u8"の代わりに何を提示する？ "s,
            u8"What do you offer for "s + valn + u8"? "s);
        s(22) = lang(u8"何を取る？ "s, u8"Take what? "s);
        s(23) = lang(u8"何を対象にする？ "s, u8"Target what? "s);
        s(24) = lang(u8"何を入れる？ "s, u8"Put what? "s);
        s(25) = lang(u8"何をもらう？ "s, u8"Which item do you want to take? "s);
        s(26) = lang(u8"何を投げる？ "s, u8"Throw what? "s);
        s(27) = lang(u8"何を盗む？ "s, u8"Steal what? "s);
        s(28) = lang(u8"何と交換する？ "s, u8"Trade what? "s);
        s(29) =
            lang(u8"何を予約する？"s, u8"Which item do you want to reserve? "s);
        if (s(invctrl) != ""s)
        {
            txtnew();
        }
        if (invsc == 0)
        {
            txt(s(invctrl));
        }
        if (invctrl == 28)
        {
            int stat = item_find(622, 3, 1);
            if (stat != -1)
            {
                p = inv_number(stat);
            }
            else
            {
                p = 0;
            }
            txtmore();
            txt(lang(
                u8"(持っているメダル: "s + p + u8"枚)"s,
                u8"(Coins: "s + p + u8")"s));
        }
        if (invctrl == 24)
        {
            if (invctrl(1) == 0)
            {
                if (gdata(20) == 36)
                {
                    txt(lang(
                        u8"ノルマ残り: "s + gdata(266) + u8"GP"s,
                        ""s + gdata(266)
                            + u8"guild points are needed to gain a rank."s));
                }
            }
        }
    }
    gsel(3);
    pos(960, 96);
    picload(fs::u8path(u8"./graphic/deco_inv.bmp"), 1);
    gsel(0);
    if (returnfromidentify == 0)
    {
        windowshadow = 1;
    }
    returnfromidentify = 0;
label_2060_internal:
    if (invsc != 0)
    {
        f = 0;
        {
            int cnt = 0;
            for (int cnt_end = cnt + (listmax); cnt < cnt_end; ++cnt)
            {
                p = list(0, cnt);
                if (inv_id(p) == invsc)
                {
                    ci = p;
                    f = 1;
                    if (ibit(4, ci))
                    {
                        if (inv_count(ci) <= 0)
                        {
                            continue;
                        }
                    }
                    break;
                }
            }
        }
        cc = 0;
        if (f == 0)
        {
            int stat = inv_find(invsc, 0);
            if (stat == -1)
            {
                txt(lang(
                    u8"そのアイテムは存在しない。"s,
                    u8"The item doesn't exist."s));
            }
            else
            {
                txtnew();
                txt(lang(
                    u8"その行為は、ワールドマップにいる間はできない。"s,
                    u8"You can't do that while you're in a global area."s));
            }
            invsc = 0;
            label_1419();
            label_2743(false);
        }
        invsc = 0;
        if (mdata(6) == 1)
        {
            if (invctrl == 9 || invctrl == 15 || invctrl == 26)
            {
                txtnew();
                txt(lang(
                    u8"その行為は、ワールドマップにいる間はできない。"s,
                    u8"You can't do that while you're in a global area."s));
                label_1419();
                label_2743(false);
            }
        }
        goto label_2062_internal;
    }
    redraw(0);
    cs_bk = -1;
    pagemax = (listmax - 1) / pagesize;
    if (page < 0)
    {
        page = pagemax;
    }
    else
    {
        if (page > pagemax)
        {
            page = 0;
        }
    }
    if (menucycle == 1)
    {
        font(lang(cfg_font1, cfg_font2), 12 + sizefix - en * 2, 0);
        y = 34;
        x = windoww - 650 + 156;
        window2(x, y, 475, 22, 5, 5);
        pos(x - 28, y - 8);
        gcopy(3, 64, 288, 50, 32);
        if (dropcontinue)
        {
            i = 4;
        }
        else
        {
            if (invally == 1)
            {
                i = 2;
            }
            else
            {
                if (invcontainer)
                {
                    i = 3;
                }
                else
                {
                    if (mdata(6) == 1)
                    {
                        i = 1;
                    }
                    else
                    {
                        i = 0;
                    }
                }
            }
        }
        {
            int cnt = 0;
            for (int cnt_end = cnt + (12); cnt < cnt_end; ++cnt)
            {
                if (cycle(cnt, i) == -1)
                {
                    break;
                }
                p = cycle(cnt, i);
                pos(x + cnt * 44 + 20, y - 24);
                gcopy(3, 288 + invicon(p) * 48, 48, 48, 48);
                if (invctrl == p)
                {
                    gmode(5 - 1, -1, 70);
                    pos(x + cnt * 44 + 20, y - 24);
                    gcopy(3, 288 + invicon(p) * 48, 48, 48, 48);
                    gmode(2);
                }
                pos(x + cnt * 44 + 46 - strlen_u(invtitle(p)) * 3, y + 7);
                color(0, 0, 0);
                if (invctrl == p)
                {
                    bmes(invtitle(p), 255, 255, 255);
                }
                else
                {
                    bmes(invtitle(p), 165, 165, 165);
                }
                if (invkey(p) != ""s)
                {
                    pos(x + cnt * 44 + 46, y + 18);
                    color(0, 0, 0);
                    bmes(u8"("s + invkey(p) + u8")"s, 235, 235, 235);
                }
            }
        }
        color(0, 0, 0);
        pos(x + 325, y + 32);
        bmes(
            ""s + key_prev + u8","s + key_next + u8",Tab "s
                + lang(u8"[メニュー切替]"s, u8"[Change]"s),
            255,
            255,
            255);
    }
label_2061_internal:
    redraw(0);
    s = lang(invtitle(invctrl) + u8"アイテムの選択"s, invtitle(invctrl));
    s(1) = strhint2 + strhint5 + strhint5b + strhint3;
    if (invctrl == 5 || invctrl == 7 || invctrl == 8 || invctrl == 9
        || invctrl == 14 || invctrl == 15 || invctrl == 26)
    {
        s(1) += strhint7;
    }
    if (invctrl == 1)
    {
        s(1) += ""s + key_mode2 + u8" "s
            + lang(u8"[保持指定]"s, u8"[Tag No-Drop]"s);
    }
    if (invctrl == 2)
    {
        if (dropcontinue == 0)
        {
            s(1) += ""s + key_mode2 + u8" "s
                + lang(u8"[連続で置く]"s, u8"[Multi Drop]"s);
        }
    }
    display_window((windoww - 640) / 2 + inf_screenx, winposy(432), 640, 432);
    if (invicon(invctrl) != -1)
    {
        pos(wx + 46, wy - 14);
        gcopy(3, 288 + invicon(invctrl) * 48, 48, 48, 48);
    }
    s = lang(u8"重さ"s, u8"Weight"s);
    if (invctrl == 11 || invctrl == 12)
    {
        s = lang(u8"値段"s, u8"Price"s);
    }
    if (invctrl == 28)
    {
        s = lang(u8"メダル"s, u8"Medal"s);
    }
    display_topic(lang(u8"アイテムの名称"s, u8"Name"s), wx + 28, wy + 30);
    display_topic(s, wx + 526, wy + 30);
    if (showresist)
    {
        pos(wx + 300, wy + 40);
        color(0, 0, 0);
        mes(lang(
            u8"火 冷 雷 闇 幻 毒 獄 音 神 沌 魔"s,
            u8"Fi Co Li Da Mi Po Nt So Nr Ch Ma"s));
    }
    pos(wx + ww - 136, wy - 6);
    gcopy(3, 960, 96, 144, 48);
    if (showresist == 0)
    {
        pos(wx + ww - 186, wy - 6);
        gcopy(3, 960, 144, 48, 72);
    }
    pos(wx + ww - 246, wy - 6);
    gcopy(3, 1008, 144, 48, 72);
    pos(wx - 6, wy - 6);
    gcopy(3, 960, 216, 48, 72);
    s = ""s + listmax + u8" items"s;
    s += u8"  (重さ合計 "s + cnvweight(cdata_inventory_weight(0)) + u8"/"s
        + cnvweight(cdata_max_inventory_weight(0)) + u8"  荷車 "s
        + cnvweight(gdata(80)) + u8")"s;
    if (invctrl == 25)
    {
        s = ""s;
    }
    display_note(s);
    if (invctrl == 25)
    {
        x = (windoww - 640) / 2 + inf_screenx + 455;
        y = winposy(432) - 32;
        w = 200;
        h = 102;
        window(x + 4, y + 4, w, h - h % 8, 0, -1);
        window(x, y, w, h - h % 8, 0, 0);
        font(lang(cfg_font1, cfg_font2), 12 + en - en * 2, 0);
        pos(x + 16, y + 17);
        mes(u8"Dv:"s + cdata_dv(tc) + u8" Pv:"s + cdata_pv(tc));
        pos(x + 16, y + 35);
        mes(lang(u8"装備重量:"s, u8"EquipWt:"s)
            + cnvweight(cdata_sum_of_equipment_weight(tc)) + ""s
            + cnveqweight(tc));
        x = wx + 40;
        y = wy + wh - 65 - wh % 8;
        pos(x, y);
        mes(lang(u8"装備箇所:"s, u8"Equip:"s));
        x += 60;
        {
            int cnt = 100;
            for (int cnt_end = cnt + (30); cnt < cnt_end; ++cnt)
            {
                if (cdata(cnt, tc) == 0)
                {
                    continue;
                }
                p = cdata(cnt, tc);
                if (p % 10000 != 0)
                {
                    color(50, 50, 200);
                }
                else
                {
                    color(100, 100, 100);
                }
                pos(x, y);
                mes(""s + bodyn(p / 10000));
                x += (strlen(bodyn(p / 10000)) + 1) * 6;
            }
        }
    }
    keyrange = 0;
    {
        int cnt = 0;
        for (int cnt_end = cnt + (pagesize); cnt < cnt_end; ++cnt)
        {
            p = pagesize * page + cnt;
            if (p >= listmax)
            {
                break;
            }
            key_list(cnt) = key_select(cnt);
            ++keyrange;
            if (cnt % 2 == 0)
            {
                pos(wx + 70, wy + 60 + cnt * 19);
                gfini(540, 18);
                gfdec2(12, 14, 16);
            }
        }
    }
    font(lang(cfg_font1, cfg_font2), 14 - en * 2, 0);
    color(0, 0, 0);
    cs_listbk();
    {
        int cnt = 0;
        for (int cnt_end = cnt + (pagesize); cnt < cnt_end; ++cnt)
        {
            p = pagesize * page + cnt;
            if (p >= listmax)
            {
                break;
            }
            p = list(0, p);
            s(0) = itemname(p, inv_number(p));
            s(1) = cnvweight(inv_weight(p) * inv_number(p));
            if (invctrl == 11)
            {
                s += u8" "s + cnvweight(inv_weight(p));
                s(1) = ""s + calcitemvalue(p, 0) + u8" gp"s;
            }
            if (invctrl == 12)
            {
                s += u8" "s + cnvweight(inv_weight(p));
                s(1) = ""s + calcitemvalue(p, 1) + u8" gp"s;
            }
            if (invctrl == 28)
            {
                s(1) = ""s + calcmedalvalue(p) + lang(u8" 枚"s, u8" Coins"s);
            }
            if (invctrl != 3 && invctrl != 11 && invctrl != 22 && invctrl != 27
                && invctrl != 28)
            {
                if (p >= 5080)
                {
                    s += lang(u8"(足元)"s, u8" (Ground)"s);
                }
            }
            {
                int cnt = 0;
                for (int cnt_end = cnt + (20); cnt < cnt_end; ++cnt)
                {
                    if (gdata(40 + cnt) == inv_id(p) + invctrl * 10000)
                    {
                        s += u8"{"s + cnt + u8"}"s;
                    }
                }
            }
            display_key(wx + 58, wy + 60 + cnt * 19 - 2, cnt);
            p(1) = inv_image(p) % 1000;
            gsel(1);
            color(0);
            boxf(0, 960, chipi(2, p(1)), chipi(3, p(1)) + 960);
            if (p(1) == 528)
            {
                gmode(2);
                pos(0, 960);
                gcopy(1, 0, 768, inf_tiles, inf_tiles);
                pos(0, 1008);
                gzoom(
                    22,
                    20,
                    5,
                    chipc(0, inv_color(p)) + 8,
                    chipc(1, inv_color(p)) + 4
                        + (chipc(3, inv_color(p)) > inf_tiles) * 8,
                    chipc(2, inv_color(p)) - 16,
                    chipc(3, inv_color(p)) - 8
                        - (chipc(3, inv_color(p)) > inf_tiles) * 10,
                    1);
                pos(6, 974);
                gcopy(1, 0, 1008, 22, 20);
                gsel(selcur);
            }
            else
            {
                if (p(1) == 531)
                {
                    pos(8, 1058 - chipc(3, inv_color(p)));
                    gcopy(
                        5,
                        chipc(0, inv_color(p)) + 8,
                        chipc(1, inv_color(p)) + 2,
                        chipc(2, inv_color(p)) - 16,
                        chipc(3, inv_color(p)) - 8);
                    gmode(4 - 1, -1, 150);
                    color(0, 0, 0);
                    pos(0, 960 + (chipc(3, inv_color(p)) == inf_tiles) * 48);
                    gcopy(
                        1,
                        144,
                        768 + (chipc(3, inv_color(p)) > inf_tiles) * 48,
                        inf_tiles,
                        chipc(3, inv_color(p))
                            + (chipc(3, inv_color(p)) > inf_tiles) * 48);
                    gmode(2);
                    gsel(selcur);
                }
                else
                {
                    pos(0, 960);
                    gcopy(
                        1,
                        chipi(0, p(1)),
                        chipi(1, p(1)),
                        chipi(2, p(1)),
                        chipi(3, p(1)));
                    gfini(chipi(2, p(1)), chipi(3, p(1)));
                    gfdec2(
                        c_col(0, inv_color(p)),
                        c_col(1, inv_color(p)),
                        c_col(2, inv_color(p)));
                    gsel(selcur);
                }
            }
            pos(wx + 37, wy + 69 + cnt * 19);
            gmode(2, chipi(2, p(1)), chipi(3, p(1)));
            grotate(
                1,
                0,
                960,
                0,
                chipi(2, p(1)) * inf_tiles / chipi(3, p(1)),
                inf_tiles);
            if (inv_body_part(p) != 0)
            {
                pos(wx + 46, wy + 72 + cnt * 18 - 3);
                gcopy(3, 12, 348, 12, 12);
                if (p == mainweapon)
                {
                    s += lang(u8"(利腕)"s, u8" (Main hand)"s);
                }
            }
            if (showresist)
            {
                equipinfo(p, wx + 300, wy + 60 + cnt * 19 + 2);
                s = strmid(s, 0, 24);
            }
            cs_list(cnt, s, wx + 84, wy + 60 + cnt * 19 - 1, 19, 0, 1, p);
            pos(wx + 600 - strlen_u(s(1)) * 7, wy + 60 + cnt * 19 + 2);
            mes(s(1));
        }
    }
    if (keyrange != 0)
    {
        cs_bk = cs;
    }
    if (showmoney)
    {
        if (showresist == 0)
        {
            font(lang(cfg_font1, cfg_font2), 13 - en * 2, 0);
            gmode(2);
            pos(wx + 340, wy + 32);
            gcopy(3, 0, 392, 24, 24);
            color(0, 0, 0);
            pos(wx + 368, wy + 37 - en * 2);
            mes(""s + cdata_gold(tc) + u8" gp"s);
        }
    }
    redraw(1);
    await(cfg_wait1);
    key_check();
    cursor_check();
    p = -1;
    invmark(invctrl) = page * 1000 + cs;
    {
        int cnt = 0;
        for (int cnt_end = cnt + (keyrange); cnt < cnt_end; ++cnt)
        {
            if (key == key_select(cnt))
            {
                p = list(0, pagesize * page + cnt);
                break;
            }
        }
    }
    if (mode == 9)
    {
        if (listmax == 0)
        {
            p = -1;
            key = key_cancel;
        }
    }
    if (p != -1)
    {
        ci = p;
        if (invctrl == 12 || invctrl == 24 && invctrl(1) != 0)
        {
            cc = -1;
        }
        else
        {
            cc = 0;
        }
    label_2062_internal:
        int stat = cargocheck();
        if (stat == 0)
        {
            goto label_2061_internal;
        }
        if (invctrl == 1)
        {
            label_2068();
            goto label_20591;
        }
        if (invctrl == 2)
        {
            if (ibit(13, ci))
            {
                snd(27);
                txt(lang(
                    u8"それはあなたの大事なものだ。<調べる>メニューから解除できる。"s,
                    u8"It's set as no-drop. You can reset it from the <examine> menu."s));
                goto label_2060_internal;
            }
            if (inv_getspace(-1) == 0)
            {
                txt(lang(
                    u8"これ以上は置けない。"s,
                    u8"You can't drop items any more."s));
                snd(27);
                goto label_2060_internal;
            }
            if (mdata(18) != 0)
            {
                if (inv_sum(-1) > mdata(18))
                {
                    if (refitem(inv_id(ci), 5) != 60000)
                    {
                        txt(lang(
                            u8"これ以上は置けない。"s,
                            u8"You can't drop items any more."s));
                        snd(27);
                        goto label_2060_internal;
                    }
                }
            }
            if (inv_number(ci) > 1)
            {
                txt(lang(
                    itemname(ci, 1) + u8"をいくつ落とす？ (1〜"s
                        + inv_number(ci) + u8") "s,
                    u8"How many? (1 to "s + inv_number(ci) + u8")"s));
                display_msg(screenmsgy, 1);
                val(0) = (windoww - 200) / 2 + inf_screenx;
                val(1) = winposy(60);
                val(2) = 8;
                val(3) = 1;
                val(4) = inv_number(ci);
                inputlog = ""s + inv_number(ci);
                label_21262();
                in = elona_int(inputlog);
                if (in > inv_number(ci))
                {
                    in = inv_number(ci);
                }
                if (in == 0 || rtval == -1)
                {
                    goto label_2060_internal;
                }
            }
            else
            {
                in = 1;
            }
            savecycle();
            dropval = 0;
            label_2193();
            if (dropcontinue)
            {
                menucycle = 1;
                ++dropcontinue;
                goto label_20591;
            }
            label_2742();
            return 0;
        }
        if (invctrl == 3 || invctrl == 11 || invctrl == 12 || invctrl == 22
            || invctrl == 24 && (invctrl(1) == 3 || invctrl(1) == 5))
        {
            if (invctrl != 3 && invctrl != 22)
            {
                if (ibit(13, ci))
                {
                    snd(27);
                    txt(lang(
                        u8"それはあなたの大事なものだ。<調べる>メニューから解除できる。"s,
                        u8"It's set as no-drop. You can reset it from the <examine> menu."s));
                    goto label_2060_internal;
                }
            }
            if (invctrl == 24)
            {
                if (invctrl(1) == 3 || invctrl(1) == 5)
                {
                    if (inv_sum(-1) >= invcontainer)
                    {
                        snd(27);
                        txt(lang(
                            u8"これ以上入らない。"s,
                            u8"The container is full."s));
                        goto label_2060_internal;
                    }
                }
                if (invctrl(1) == 5)
                {
                    if (inv_weight(ci) >= efp * 100)
                    {
                        snd(27);
                        txt(lang(
                            u8"重さが"s + cnvweight(efp * 100)
                                + u8"以上の物は入らない。"s,
                            u8"The container can only hold items weight less than "s
                                + cnvweight(efp * 100) + u8"."s));
                        goto label_2060_internal;
                    }
                    if (inv_weight(ci) <= 0)
                    {
                        snd(27);
                        txt(lang(
                            u8"荷物は入らない。"s,
                            u8"The container cannot hold cargos"s));
                        goto label_2060_internal;
                    }
                }
                if (invctrl(1) == 5)
                {
                    int stat = actionsp(0, 10);
                    if (stat == 0)
                    {
                        txt(lang(
                            u8"疲労し過ぎて失敗した！"s,
                            u8"You are too exhausted!"s));
                        goto label_2063_internal;
                    }
                }
            }
            if (invctrl == 22)
            {
                if (invctrl(1) == 1)
                {
                    if (gdata(97) < 1)
                    {
                        txt(lang(
                            u8"遺産の相続権を持っていない。"s,
                            u8"You don't have a claim."s));
                        goto label_2060_internal;
                    }
                }
                if (invctrl(1) == 5)
                {
                    int stat = actionsp(0, 10);
                    if (stat == 0)
                    {
                        txt(lang(
                            u8"疲労し過ぎて失敗した！"s,
                            u8"You are too exhausted!"s));
                        goto label_2063_internal;
                    }
                }
            }
            if (inv_own_state(ci) > 0 && inv_own_state(ci) < 3)
            {
                snd(27);
                ++msgdup;
                if (inv_own_state(ci) == 2)
                {
                    txt(lang(
                        u8"それは持ち運べない。"s, u8"You can't carry it."s));
                }
                if (inv_own_state(ci) == 1)
                {
                    txt(lang(
                            u8"それはあなたの物ではない。"s,
                            u8"It's not your property."s),
                        lang(
                            u8"盗むなんてとんでもない。"s,
                            u8"You can't just take it."s),
                        lang(u8"それは拾えない。"s, u8"It's not yours."s));
                }
                label_1419();
                label_2743(false);
            }
            page_save();
            if (mode == 6 && inv_number(ci) > 1 && invctrl != 22)
            {
                if (invctrl == 11)
                {
                    txt(lang(
                        itemname(ci, 1) + u8"をいくつ買う？ (1〜"s
                            + inv_number(ci) + u8") "s,
                        u8"How many? (1 to "s + inv_number(ci) + u8")"s));
                }
                if (invctrl == 12)
                {
                    txt(lang(
                        itemname(ci, 1) + u8"をいくつ売る？ (1〜"s
                            + inv_number(ci) + u8") "s,
                        u8"How many? (1 to "s + inv_number(ci) + u8")"s));
                }
                display_msg(screenmsgy, 2);
                val(0) = (windoww - 200) / 2 + inf_screenx;
                val(1) = winposy(60);
                val(2) = 8;
                val(3) = 1;
                val(4) = inv_number(ci);
                inputlog = ""s + inv_number(ci);
                label_21262();
                in = elona_int(inputlog);
                if (in > inv_number(ci))
                {
                    in = inv_number(ci);
                }
                if (in == 0 || rtval == -1)
                {
                    screenupdate = -1;
                    label_1419();
                    stick(p);
                    goto label_2060_internal;
                }
            }
            else
            {
                in = inv_number(ci);
            }
            if (mode == 6 && invctrl != 22 && invctrl != 24)
            {
                if (invctrl == 11)
                {
                    txt(lang(
                        itemname(ci, in) + u8"を "s + in * calcitemvalue(ci, 0)
                            + u8" gp で買う？"s,
                        u8"Do you really want to buy "s + itemname(ci, in)
                            + u8" for "s + in * calcitemvalue(ci, 0)
                            + u8" gold pieces?"s));
                }
                if (invctrl == 12)
                {
                    txt(lang(
                        itemname(ci, in) + u8"を "s + in * calcitemvalue(ci, 1)
                            + u8" gp で売る？"s,
                        u8"Do you really want to sell "s + itemname(ci, in)
                            + u8" for "s + in * calcitemvalue(ci, 1)
                            + u8" gold pieces?"s));
                }
                promptl(0, 0) = stryes;
                promptl(1, 0) = u8"y"s;
                promptl(2, 0) = u8"0"s;
                promptl(0, 1) = strno;
                promptl(1, 1) = u8"n"s;
                promptl(2, 1) = u8"1"s;
                promptmax = 2;
                val(0) = promptx;
                val(1) = prompty;
                val(2) = 160;
                val(3) = 1;
                label_2131();
                if (rtval != 0)
                {
                    screenupdate = -1;
                    label_1419();
                    goto label_20591;
                }
                if (invctrl == 11)
                {
                    if (calcitemvalue(ci, 0) * in > cdata_gold(0))
                    {
                        screenupdate = -1;
                        label_1419();
                        txt(lang(
                                u8"あなたは財布を開いてがっかりした…"s,
                                u8"You check your wallet and shake your head."s),
                            lang(
                                u8"もっと稼がないと買えない！"s,
                                u8"You need to earn more money!"s));
                        msgkeep = 1;
                        goto label_20591;
                    }
                }
                if (invctrl == 12)
                {
                    if (cdata_character_role(tc) != 1009)
                    {
                        if (calcitemvalue(ci, 1) * in > cdata_gold(tc))
                        {
                            screenupdate = -1;
                            label_1419();
                            txt(lang(
                                name(tc) + u8"は財布を開いてがっかりした…"s,
                                name(tc) + u8" checks "s + his(tc)
                                    + u8" wallet and shake "s + his(tc)
                                    + u8" head."s));
                            msgkeep = 1;
                            goto label_20591;
                        }
                    }
                }
            }
            int stat = label_2192();
            if (stat == 0)
            {
                goto label_20591;
            }
            if (stat == -1)
            {
                label_2742();
                return 0;
            }
            if (invctrl == 22)
            {
                if (invctrl(1) == 1)
                {
                    --gdata(97);
                    if (invctrl(1) == 1)
                    {
                        txt(lang(
                            u8"残り"s + gdata(97)
                                + u8"個分のアイテムの相続権を持っている。"s,
                            u8"You can claim "s + gdata(97)
                                + u8" more heirloom"s + _s2(gdata(97))
                                + u8"."s));
                    }
                }
                if (invctrl(1) == 4)
                {
                    ++gdata(812);
                    invsubroutine = 0;
                    return 1;
                }
            }
            screenupdate = -1;
            label_1419();
            goto label_20591;
        }
        if (invctrl == 5)
        {
            if (ibit(13, ci))
            {
                snd(27);
                txt(lang(
                    u8"それはあなたの大事なものだ。<調べる>メニューから解除できる。"s,
                    u8"It's set as no-drop. You can reset it from the <examine> menu."s));
                goto label_2060_internal;
            }
            screenupdate = -1;
            label_1419();
            savecycle();
            if (cdata_nutrition(0) > 10000)
            {
                txt(lang(
                        u8"今はとても食べられない。"s,
                        u8"Your are too full to eat."s),
                    lang(
                        u8"腹がさける…"s,
                        u8"You are too bloated to eat any more."s),
                    lang(
                        u8"まだ腹は減っていない。"s,
                        u8"Your stomach can't digest any more."s));
                label_1419();
                label_2743(false);
            }
            label_2198();
            return 0;
        }
        if (invctrl == 6)
        {
            if (cc == 0)
            {
                if (trait(161) != 0)
                {
                    if (inv_weight(ci) >= 1000)
                    {
                        txt(lang(
                            u8"それは重すぎて装備できない。"s,
                            u8"It's too heavy to equip."s));
                        goto label_2060_internal;
                    }
                }
            }
            r1 = cc;
            label_2194();
            r1 = cc;
            label_1477();
            screenupdate = -1;
            label_1419();
            snd(13);
            txtnew();
            txt(lang(
                itemname(ci) + u8"を装備した。"s,
                u8"You equip "s + itemname(ci) + u8"."s));
            gdata(808) = 1;
            if (inv_curse_state(ci) == -1)
            {
                txt(lang(
                    name(cc) + u8"は急に寒気がしてふるえた。"s,
                    u8"You suddenly feel a chill and shudder."s));
            }
            if (inv_curse_state(ci) == -2)
            {
                txt(lang(
                    name(cc) + u8"は破滅への道を歩み始めた。"s,
                    u8"You are now one step closer to doom."s));
            }
            if (inv_curse_state(ci) == 1)
            {
                txt(lang(
                    name(cc) + u8"は何かに見守られている感じがした。"s,
                    u8"You feel as someone is watching you intently."s));
            }
            if (cdata(body, cc) / 10000 == 5)
            {
                label_2049();
            }
            menucycle = 1;
            label_2050();
            return 0;
        }
        if (invctrl == 7)
        {
            screenupdate = -1;
            label_1419();
            savecycle();
            label_2197();
            return 0;
        }
        if (invctrl == 8)
        {
            screenupdate = -1;
            label_1419();
            savecycle();
            label_2199();
            return 0;
        }
        if (invctrl == 9)
        {
            screenupdate = -1;
            label_1419();
            savecycle();
            label_2200();
            return 0;
        }
        if (invctrl == 10)
        {
            if (ibit(13, ci))
            {
                snd(27);
                txt(lang(
                    u8"それはあなたの大事なものだ。<調べる>メニューから解除できる。"s,
                    u8"It's set as no-drop. You can reset it from the <examine> menu."s));
                goto label_2060_internal;
            }
            ti = inv_getfreeid(tc);
            if (cdata_sleep(tc))
            {
                txt(lang(
                    name(tc) + u8"は眠っている。"s,
                    name(tc) + u8" "s + is(tc) + u8" sleeping."s));
                snd(27);
                goto label_2060_internal;
            }
            if (ti == -1)
            {
                txt(lang(
                    name(tc) + u8"はこれ以上持てない。"s,
                    his(tc) + u8" inventory is full."s));
                snd(27);
                goto label_2060_internal;
            }
            reftype = refitem(inv_id(ci), 5);
            if (inv_id(ci) == 729)
            {
                txt(lang(
                    u8"あなたは"s + name(tc) + u8"に"s + itemname(ci, 1)
                        + u8"をプレゼントした。"s,
                    u8"You give "s + name(tc) + u8" "s + itemname(ci, 1)
                        + u8"."s));
                --inv_number(ci);
                label_1521();
                txt(lang(
                    u8"「え、これを"s + _ore(3) + u8"にくれるの"s + _ka(1) + ""s
                        + _thanks(2) + u8"」"s,
                    cnvtalk(u8"Thank you!"s)));
                modimp(tc, giftvalue(inv_param4(ci)));
                cdata_emotion_icon(tc) = 317;
                label_1419();
                label_2743(false);
            }
            f = 0;
            p = sdata(10, tc) * 500 + sdata(11, tc) * 500
                + sdata(153, tc) * 2500 + 25000;
            if (cdata_id(tc) == 265)
            {
                p *= 5;
            }
            if (inv_weight_(tc) + inv_weight(ci) > p)
            {
                f = 1;
            }
            if (cdata_id(tc) != 265)
            {
                if (reftype == 60000)
                {
                    f = 2;
                }
                if (reftype == 64000)
                {
                    f = 3;
                }
            }
            if (inv_weight(ci) < 0)
            {
                f = 4;
            }
            if (f)
            {
                s(0) = "";
                s(1) = lang(u8"重すぎ"s, u8"Too heavy!"s);
                s(2) = lang(u8"無理"s, u8"No way."s);
                s(3) = lang(u8"いらん"s, u8"I don't want it."s);
                s(4) = lang(u8"イヤ！"s, u8"Never!"s);
                snd(27);
                txt(lang(name(tc) + u8"「"s + s(f) + u8"」"s, cnvtalk(s(f))));
                goto label_2060_internal;
            }
            f = 0;
            if (cdata_relationship(tc) == 10)
            {
                f = 1;
            }
            else
            {
                if (inv_identification_state(ci) < 2)
                {
                    snd(27);
                    txt(lang(
                        u8"「そんな得体の知れないものはいらない"s + _yo()
                            + u8"」"s,
                        cnvtalk(u8"I dont't want it. It's too creepy."s)));
                    goto label_2060_internal;
                }
                if (inv_curse_state(ci) <= -1)
                {
                    snd(27);
                    txt(lang(
                        u8"「それ、呪われてい"s + _ru() + u8"」"s,
                        cnvtalk(u8"It's cursed!"s)));
                    goto label_2060_internal;
                }
                if (reftype == 53000)
                {
                    f = 1;
                    if (instr(filter_item(inv_id(ci)), 0, u8"/neg/"s) != -1)
                    {
                        f = 0;
                    }
                    if (inv_id(ci) == 16 || inv_id(ci) == 245)
                    {
                        f = 0;
                    }
                }
                if (reftype == 52000)
                {
                    f = 1;
                    if (refitem(inv_id(ci), 9) == 52002)
                    {
                        if (cdata_drunk(tc))
                        {
                            snd(27);
                            txt(lang(
                                u8"「もう飲めない"s + _yo() + u8"」"s,
                                cnvtalk(u8"Enough for me."s)));
                            goto label_2060_internal;
                        }
                    }
                    if (instr(filter_item(inv_id(ci)), 0, u8"/neg/"s) != -1)
                    {
                        f = 0;
                    }
                    if (instr(filter_item(inv_id(ci)), 0, u8"/nogive/"s) != -1)
                    {
                        f = 0;
                    }
                    if (cbit(978, tc))
                    {
                        if (inv_id(ci) == 262 || inv_id(ci) == 519
                            || inv_id(ci) == 392)
                        {
                            f = 1;
                            txt(lang(
                                u8"「おろす…」"s, cnvtalk(u8"Abortion..."s)));
                        }
                    }
                }
            }
            if (f)
            {
                snd(13);
                txt(lang(
                    itemname(ci, 1) + u8"を渡した。"s,
                    u8"You hand "s + itemname(ci, 1) + u8" to "s + name(tc)
                        + u8"."s));
                if (inv_id(ci) == 477 || inv_id(ci) == 473)
                {
                    txtef(2);
                    txt(lang(
                        name(tc) + u8"は顔を赤らめた。"s,
                        name(tc) + u8" blushes."s));
                    modimp(tc, 15);
                    cdata_emotion_icon(tc) = 317;
                }
                if (inv_id(ci) == 620)
                {
                    txtmore();
                    txtef(8);
                    txt(lang(
                        name(tc) + u8"は激怒して"s + itemname(ci, 1)
                            + u8"を叩き割った。"s,
                        name(tc) + u8" throws it on the ground angrily."s));
                    snd(47);
                    txtmore();
                    txtef(9);
                    txt(lang(
                            name(tc) + u8"「サイテー！！」"s,
                            cnvtalk(u8"You scum!"s)),
                        lang(
                            name(tc) + u8"「このヘンタイ！」"s,
                            cnvtalk(u8"What are you trying to do!"s)),
                        lang(
                            name(tc) + u8"「ガード！ガード！ガード！」"s,
                            cnvtalk(u8"Guard! Guard! Guard!"s)));
                    modimp(tc, -20);
                    cdata_emotion_icon(tc) = 318;
                    --inv_number(ci);
                    goto label_20591;
                }
                item_copy(ci, ti);
                --inv_number(ci);
                inv_number(ti) = 1;
                item_stack(tc, ti, 1);
                ci = ti;
                rc = tc;
                label_2663();
                label_2666();
                if (tc < 16)
                {
                    create_pcpic(tc, 1);
                }
                r1 = tc;
                label_1477();
                label_1521();
                if (invally == 1)
                {
                    goto label_20591;
                }
                label_1419();
                label_2742();
                return 0;
            }
            snd(27);
            txt(lang(
                name(tc) + u8"は"s + itemname(ci, 1) + u8"を受け取らない。"s,
                name(tc) + u8" refuse"s + _s(tc) + u8" to take "s
                    + itemname(ci, 1) + u8"."s));
            goto label_2060_internal;
        }
        if (invctrl == 13)
        {
            screenupdate = -1;
            label_1419();
            int stat = item_identify(ci, -1, efp);
            if (stat == 0)
            {
                txt(lang(
                    u8"新しい知識は得られなかった。より上位の鑑定で調べる必要がある。"s,
                    u8"You need higher identification to gain new knowledge."s));
            }
            else
            {
                if (stat < 3)
                {
                    txt(lang(
                        u8"それは"s + itemname(ci, inv_number(ci))
                            + u8"だと判明したが、完全には鑑定できなかった。"s,
                        u8"The item is half-identified as "s + itemname(ci, 1)
                            + u8"."s));
                }
                else
                {
                    txt(lang(
                        u8"それは"s + itemname(ci, inv_number(ci))
                            + u8"だと完全に判明した。"s,
                        u8"The item is fully identified as "s + itemname(ci, 1)
                            + u8"."s));
                }
            }
            item_stack(0, ci, 1);
            invsubroutine = 0;
            return 1;
        }
        if (invctrl == 14)
        {
            savecycle();
            label_2228();
            return 0;
        }
        if (invctrl == 16)
        {
            screenupdate = -1;
            label_1419();
            invsubroutine = 0;
            return 1;
        }
        if (invctrl == 15)
        {
            screenupdate = -1;
            label_1419();
            savecycle();
            label_2212();
            return 0;
        }
        if (invctrl == 17)
        {
            cidip = ci;
            savecycle();
            invctrl = 18;
            txtnew();
            snd(26);
            goto label_20591;
        }
        if (invctrl == 18)
        {
            screenupdate = -1;
            label_1419();
            label_2227();
            return 0;
        }
        if (invctrl == 19)
        {
            if (ibit(13, ci))
            {
                snd(27);
                txt(lang(
                    u8"それはあなたの大事なものだ。<調べる>メニューから解除できる。"s,
                    u8"It's set as no-drop. You can reset it from the <examine> menu."s));
                goto label_2060_internal;
            }
            screenupdate = -1;
            label_1419();
            savecycle();
            label_1891();
            return 0;
        }
        if (invctrl == 20)
        {
            citrade = ci;
            invctrl = 21;
            snd(26);
            goto label_20591;
        }
        if (invctrl == 21)
        {
            if (ibit(13, ci))
            {
                snd(27);
                txt(lang(
                    u8"それはあなたの大事なものだ。<調べる>メニューから解除できる。"s,
                    u8"It's set as no-drop. You can reset it from the <examine> menu."s));
                goto label_2060_internal;
            }
            if (cdata_continuous_action_id(tc) != 0)
            {
                cdata_continuous_action_id(tc) = 0;
                cdata_continuous_action_turn(tc) = 0;
                cdata_continuous_action_item(tc) = 0;
            }
            snd(13);
            ibitmod(12, citrade, 0);
            txt(lang(
                itemname(ci) + u8"を"s + itemname(citrade) + u8"と交換した。"s,
                u8"You receive "s + itemname(citrade) + u8" in exchange for "s
                    + itemname(ci) + u8"."s));
            if (inv_body_part(citrade) != 0)
            {
                p = inv_body_part(citrade);
                cdata(p, tc) = cdata(p, tc) / 10000 * 10000;
                inv_body_part(citrade) = 0;
            }
            ti = citrade;
            label_2191();
            convertartifact(ci);
            rc = tc;
            ci = citrade;
            if (cdata_item_which_will_be_used(rc) == ci)
            {
                cdata_item_which_will_be_used(rc) = 0;
            }
            label_2666();
            if (tc >= 16)
            {
                label_2668();
            }
            label_2665();
            r1 = tc;
            label_1477();
            label_1521();
            invsubroutine = 0;
            return 1;
        }
        if (invctrl == 23)
        {
            item_separate(ci);
            invsubroutine = 0;
            return 1;
        }
        if (invctrl == 24)
        {
            if (invctrl(1) == 0)
            {
                snd(100);
                if (gdata(20) == 36)
                {
                    gdata(266) -= (inv_param1(ci) + 1) * inv_number(ci);
                    if (gdata(266) <= 0)
                    {
                        gdata(266) = 0;
                    }
                    txtef(2);
                    txt(lang(
                            itemname(ci) + u8"を納入した"s,
                            u8"You deliver "s + itemname(ci) + u8". "s)
                        + u8"("s + (inv_param1(ci) + 1) * inv_number(ci)
                        + u8" Guild Point)"s);
                    if (gdata(266) == 0)
                    {
                        snd(51);
                        txtef(2);
                        txt(lang(
                            u8"ノルマを達成した！"s,
                            u8"You fulfill the quota!"s));
                    }
                }
                else
                {
                    qdata(13, gdata(72)) += inv_weight(ci) * inv_number(ci);
                    txtef(2);
                    txt(lang(
                            itemname(ci) + u8"を納入した。"s,
                            u8"You deliver"s + itemname(ci) + u8"."s)
                        + u8" +"s + cnvweight(inv_weight(ci) * inv_number(ci))
                        + lang(u8"  納入済み"s, u8" Delivered "s) + u8"("s
                        + cnvweight(qdata(13, gdata(72))) + u8") "s
                        + lang(u8"納入ノルマ"s, u8"Quota "s) + u8"("s
                        + cnvweight(qdata(12, gdata(72))) + u8")"s);
                }
                inv_number(ci) = 0;
                label_1521();
                goto label_20591;
            }
            if (invctrl(1) == 2)
            {
                if (cdata_gold(0) < inv_subname(ci))
                {
                    snd(27);
                    txt(lang(
                        u8"金が足りない…"s, u8"You don't have enough money."s));
                    goto label_2060_internal;
                }
                if (gdata(179) <= 0)
                {
                    snd(27);
                    txt(lang(
                        u8"まだ納税する必要はない。"s,
                        u8"You don't have to pay your tax yet."s));
                    goto label_20591;
                }
                cdata_gold(0) -= inv_subname(ci);
                snd(12);
                txtef(2);
                txt(lang(
                    itemname(ci) + u8"を支払った。"s,
                    u8"You pay "s + itemname(ci) + u8"."s));
                --inv_number(ci);
                --gdata(179);
                label_1521();
                screenupdate = -1;
                label_1419();
                goto label_20591;
            }
        }
        if (invctrl == 25)
        {
            ti = inv_getfreeid(0);
            if (ti == -1)
            {
                txt(lang(
                    u8"バックパックが一杯だ。"s, u8"Your inventory is full."s));
                goto label_2060_internal;
            }
            f = 0;
            if (refitem(inv_id(ci), 5) == 77000)
            {
                f = 2;
            }
            if (f != 0)
            {
                s(0) = "";
                s(1) = lang(u8"やだ"s, u8"No!"s);
                s(2) = lang(u8"あげないよ"s, u8"It's mine."s);
                s(3) = lang(u8"だめ"s, u8"Get off!"s);
                s(4) = lang(u8"イヤ！"s, u8"Never."s);
                snd(27);
                txtef(4);
                txt(lang(name(tc) + u8"「"s + s(f) + u8"」"s, cnvtalk(s(f))));
                goto label_2060_internal;
            }
            if (inv_body_part(ci) != 0)
            {
                if (inv_curse_state(ci) == -1 || inv_curse_state(ci) == -2)
                {
                    txt(lang(
                        itemname(ci) + u8"は呪われていて外せない。"s,
                        ""s + itemname(ci)
                            + u8" is cursed and can't be taken off."s));
                    goto label_20591;
                }
                p = inv_body_part(ci);
                cdata(p, tc) = cdata(p, tc) / 10000 * 10000;
                inv_body_part(ci) = 0;
            }
            if (inv_id(ci) == 477 || inv_id(ci) == 473)
            {
                txtef(8);
                txt(lang(
                    name(tc) + u8"は激怒して"s + itemname(ci, 1)
                        + u8"を飲み込んだ。"s,
                    name(tc) + u8" swallows "s + itemname(ci, 1)
                        + u8" angrily."s));
                snd(65);
                modimp(tc, -20);
                cdata_emotion_icon(tc) = 318;
                --inv_number(ci);
                goto label_20591;
            }
            snd(13);
            ibitmod(12, ci, 0);
            if (inv_id(ci) == 54)
            {
                in = inv_number(ci);
            }
            else
            {
                in = 1;
            }
            txt(lang(
                itemname(ci, in) + u8"を受け取った。"s,
                u8"You take "s + itemname(ci, in) + u8"."s));
            if (inv_id(ci) == 54)
            {
                cdata_gold(0) += in;
                inv_number(ci) = 0;
            }
            else
            {
                item_copy(ci, ti);
                inv_number(ci) -= in;
                inv_number(ti) = in;
                item_stack(0, ti, 1);
                convertartifact(ti);
            }
            rc = tc;
            label_2666();
            if (tc < 16)
            {
                create_pcpic(tc, 1);
            }
            r1 = tc;
            label_1477();
            label_1521();
            goto label_20591;
        }
        if (invctrl == 26)
        {
            savecycle();
            int stat = label_1947();
            if (stat != 1)
            {
                if (stat == 0)
                {
                    txt(lang(
                        u8"その場所は見えない。"s,
                        u8"You can't see the location."s));
                    label_1419();
                }
                label_2743(false);
            }
            if (chipm(7, map(tlocx, tlocy, 0)) & 4)
            {
                txt(lang(
                    u8"そこには投げられない。"s,
                    u8"The location is blocked."s));
                label_1419();
                label_2743(false);
            }
            label_2189();
            return 0;
        }
        if (invctrl == 27)
        {
            label_2237();
            invsubroutine = 0;
            return 1;
        }
        if (invctrl == 28)
        {
            txtnew();
            ti = inv_getfreeid(0);
            if (ti == -1)
            {
                txt(lang(
                    u8"これ以上持てない。"s, u8"Your inventory is full."s));
                snd(27);
                goto label_20591;
            }
            int stat = item_find(622, 3, 1);
            if (stat != -1)
            {
                i = stat;
                p = inv_number(i);
            }
            else
            {
                p = 0;
            }
            if (p < calcmedalvalue(ci))
            {
                txt(lang(
                    u8"メダルの数が足りない…"s,
                    u8"You don't have enough coins."s));
                snd(27);
                goto label_20591;
            }
            inv_number(i) -= calcmedalvalue(ci);
            snd(12);
            item_copy(ci, ti);
            txt(lang(
                ""s + itemname(ti, 1) + u8"を受け取った！"s,
                u8"You receive "s + itemname(ti, 1) + u8"!"s));
            item_stack(0, ti, 1);
            convertartifact(ti, 1);
            goto label_20591;
        }
    }
    if (key == key_identify)
    {
        if (listmax != 0)
        {
            ci = list(0, pagesize * page + cs);
            label_2068();
            goto label_20591;
        }
    }
    if (key == key_pageup)
    {
        if (pagemax != 0)
        {
            snd(1);
            ++page;
            goto label_2060_internal;
        }
    }
    if (key == key_pagedown)
    {
        if (pagemax != 0)
        {
            snd(1);
            --page;
            goto label_2060_internal;
        }
    }
    if (menucycle == 1)
    {
        if (key == key_next || key == key_prev)
        {
            if (dropcontinue)
            {
                i = 4;
            }
            else
            {
                if (invally == 1)
                {
                    i = 2;
                }
                else
                {
                    if (invcontainer)
                    {
                        i = 3;
                    }
                    else
                    {
                        if (mdata(6) == 1)
                        {
                            i = 1;
                        }
                        else
                        {
                            i = 0;
                        }
                    }
                }
            }
            p = -1;
            {
                int cnt = 0;
                for (int cnt_end = cnt + (12); cnt < cnt_end; ++cnt)
                {
                    if (invctrl == cycle(cnt, i))
                    {
                        p = cnt;
                        break;
                    }
                }
            }
            if (p != -1)
            {
                if (key == key_next)
                {
                    ++p;
                    if (cycle(p, i) == -1)
                    {
                        p = 0;
                    }
                }
                if (key == key_prev)
                {
                    --p;
                    if (p < 0)
                    {
                        p = cyclemax(i);
                    }
                }
                if (invctrl != cycle(p, i))
                {
                    invctrl = cycle(p, i);
                    snd(100);
                    screenupdate = -1;
                    label_1419();
                    goto label_20591;
                }
            }
        }
    }
    if (key == key_mode2)
    {
        if (invctrl == 1)
        {
            ci = list(0, pagesize * page + cs);
            if (ibit(13, ci) == 0)
            {
                ibitmod(13, ci, 1);
                txt(lang(
                    itemname(ci) + u8"を大事なものに指定した。"s,
                    u8"You set "s + itemname(ci) + u8" as no-drop."s));
            }
            else
            {
                ibitmod(13, ci, 0);
                txt(lang(
                    itemname(ci) + u8"はもう大事なものではない。"s,
                    itemname(ci) + u8" is no longer set as no-drop."s));
            }
        }
        if (invctrl == 2)
        {
            if (dropcontinue == 0)
            {
                txt(lang(
                    u8"続けてアイテムを置くことができる。"s,
                    u8"You can continuously drop items."s));
                dropcontinue = 1;
                snd(100);
                screenupdate = -1;
                label_1419();
                goto label_20591;
            }
        }
    }
    if (key == key_mode)
    {
        if (showresist == 1)
        {
            showresist = 0;
        }
        else
        {
            showresist = 1;
        }
        snd(1);
        goto label_2060_internal;
    }
    if (key == key_cancel)
    {
    label_2063_internal:
        savecycle();
        if (invctrl == 22)
        {
            if (invctrl(1) == 0)
            {
                if (listmax > 0)
                {
                    txt(lang(
                        u8"まだアイテムが残っているがいい？"s,
                        u8"Really leave these items?"s));
                    promptl(0, 0) = stryes;
                    promptl(1, 0) = u8"y"s;
                    promptl(2, 0) = u8"0"s;
                    promptl(0, 1) = strno;
                    promptl(1, 1) = u8"n"s;
                    promptl(2, 1) = u8"1"s;
                    promptmax = 2;
                    val(0) = promptx;
                    val(1) = prompty;
                    val(2) = 160;
                    val(3) = 1;
                    label_2131();
                    if (rtval != 0)
                    {
                        goto label_2060_internal;
                    }
                }
            }
        }
        cc = 0;
        efcancel = 1;
        if (invsubroutine == 1)
        {
            invsubroutine = 0;
            return 0;
        }
        if (invctrl == 6)
        {
            screenupdate = -1;
            label_1419();
            menucycle = 1;
            label_2050();
            return 0;
        }
        if (invctrl == 11 || invctrl == 12 || invctrl == 22 || invctrl == 28)
        {
            label_2264();
            return 0;
        }
        if (invally == 1)
        {
            invally = 0;
        }
        if (dropcontinue)
        {
            dropcontinue = 0;
            label_2742();
            return 0;
        }
        screenupdate = 0;
        label_1419();
        label_2743(false);
    }
    if (invctrl == 5 || invctrl == 7 || invctrl == 8 || invctrl == 9
        || invctrl == 14 || invctrl == 15 || invctrl == 26)
    {
        if (key == u8"sc"s)
        {
            p = list(0, pagesize * page + cs);
            if (inv_weight(p) < 0)
            {
                snd(27);
                txt(lang(
                    u8"荷車の荷物は登録できない。"s,
                    u8"You can't make a shortcut for cargo stuff."s));
                goto label_20591;
            }
            snd(20);
            p = inv_id(list(0, pagesize * page + cs)) + invctrl * 10000;
            if (gdata(40 + sc) == p)
            {
                gdata(40 + sc) = 0;
                goto label_2060_internal;
            }
            {
                int cnt = 0;
                for (int cnt_end = cnt + (20); cnt < cnt_end; ++cnt)
                {
                    if (gdata(40 + cnt) == p)
                    {
                        gdata(40 + cnt) = 0;
                    }
                }
            }
            gdata(40 + sc) = p;
            txt(lang(
                u8"{"s + sc + u8"}キーにショートカットを割り当てた。"s,
                u8"You have assigned the shortcut to {"s + sc + u8"} key."s));
            goto label_2060_internal;
        }
    }
    goto label_2061_internal;
}


} // namespace elona

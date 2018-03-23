#pragma once



namespace elona
{

enum class curse_state_t
{
    doomed = -2,
    cursed = -1,
    none = 0,
    blessed = 1,
};


inline bool is_cursed(curse_state_t s)
{
    return s == curse_state_t::doomed || s == curse_state_t::cursed;
}

} // namespace elona
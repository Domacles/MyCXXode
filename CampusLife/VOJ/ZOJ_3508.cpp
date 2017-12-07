#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
//#undef _DEBUG
struct Soldier
{
    int minW;
    int maxW;
};
struct SoldierCmp
{
    bool operator()(const Soldier &a, const Soldier &b)
    {
        return a.maxW < b.maxW || a.maxW == b.maxW && a.minW < b.minW;
    }
};
vector <Soldier> soldier;
vector <int> weapon;
/* *************************************************************************
将 soldier 按 maxW 排序，将 weapon 按重量排序，每次为一个 soldier 非配武器，
将可能的最小重量的武器分配给他。
************************************************************************* */
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2)
    {
        soldier.resize(n);
        for(int i=0; i<n; ++i)
            scanf("%d%d", &soldier[i].minW, &soldier[i].maxW);

        weapon.resize(m);
        for(int i=0; i<m; ++i)
            scanf("%d", &weapon[i]);

        sort(soldier.begin(), soldier.end(), SoldierCmp());
        sort(weapon.begin(), weapon.end());

        int ans = 0;
        vector <bool> marked(weapon.size(), false);
        for(int s=0; s<soldier.size(); ++s)
        {
            int w = 0;
            while(w < weapon.size() && (marked[w] || weapon[w] < soldier[s].minW))
                ++w;

            if(w < weapon.size() && soldier[s].minW <= weapon[w] && weapon[w] <= soldier[s].maxW)
            {
                ++ans;
                marked[w] = true;
            }
        }
        printf("%d/n", ans);
    }
    return 0;
}

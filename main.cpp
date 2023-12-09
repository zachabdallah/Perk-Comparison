//
//  main.cpp
//  Perk Comparison
//
//  Created by Zach Abdallah on 1/14/23.
//

#include <iostream>
using namespace std;
//at 3000 weapon dmg and 300,000 dpm;
//p6a1,a4e2: +18.7% //This makes c4e2 an oh switch.
//a4p2,e4(x): +16.1% //No switch
//p6a1,(c4)e2: +12.4% //No switch //c4 is not calculated
//p6,(c4)e2: +10.3%

//p6: + 7.5%
//e4: + 5.2%
//a4: + 7.6%
//this calculator does not take into account the caroming perk as it is too complex and rng based to really calculate its damage increase. It is not enough to simply account for the pure dps being added from greater richochet because most of the damage in c4 comes from excess adrenaline being gained and the occasional ruby bolt proc.
//obviously p6a1 + a4e2 (c4e2 switch) is the best by a large margin but would be kind of a pain as greater ricochet is used about every 10 seconds. The runner up would not use a switch and would be very comfortable to use.
//precise works by normalizing weapon damage in a way where the minimum damage is increased by a percentage of it's maximum. Equillibrium is similar in that it normalizes damage range but it does so by affecting both the minimum and maximum hit. Because the Range cb style utilizes bleeds often, it may be a good idea to camp a4 and use caroming as a switch because both precise and equillibrium do not affect bleeds. They do however accumulate into aftershock procs which is highly beneficial.

int main() {

    double weapon_dmg = 3000.0;
    double dpm = 300000.0;
    const double dpm_dont_change = dpm;
    cout << "base dpm : " << dpm << ", weapon damage : " << weapon_dmg << endl;
    cout << "what precise level? " << endl;
    int plvl = 0; //precise level
    cin >> plvl;
    if (plvl > 0){
        double pmod = 0.0; //precise modifier
        for (int i = 0; i < plvl; ++i){
            pmod += .0125;
        }
        pmod+= 1; // to multiply the dpm later (e.g. 1.075)
        cout << "Precise mod: " << pmod << endl;
        cout << "New dpm : " << (dpm * pmod) << endl;
        double precise_dmg_inc = (((dpm * pmod) / dpm) - 1) * 100;
        cout << "damage increase: " << precise_dmg_inc << "%" << endl;
        
        //now im going to modify dpm with precise instead of just printing it
        dpm *= pmod;
        cout << "New Dpm after Precise : " << dpm << endl;
        cout << endl << endl;
    }
    
    int elvl;
    double emod = 0.0;
    cout << "equillibrium level? " << endl;
    cin >> elvl;
    if (elvl > 0){
        for (int i = 0; i < elvl; ++i){
            emod += 0.013;
        }
        emod += 1;
        
        double equillibrium_dmg_inc = (((dpm * emod) / dpm) -1) * 100;
        dpm *= emod;
        cout << "dpm after equillibrium : " << dpm << endl;
        cout << "damage increase from equillibrium: " << equillibrium_dmg_inc << "%" << endl;
        cout << endl << endl;
    }
    
    cout << "what level aftershock?" << endl;
    int alvl;
    cin >> alvl;
    if (alvl > 0){
        double aftershock = 0.0;
        if (alvl == 1){
            aftershock = 0.318 * weapon_dmg; // aftershock damage
            cout << "aftershock proc dmg: " << aftershock << endl;
        }
        else if (alvl == 2){
            aftershock = 0.636 * weapon_dmg; // aftershock damage
            cout << "aftershock proc dmg: " << aftershock << endl;
        }
        else if (alvl == 3){
            aftershock = 0.954 * weapon_dmg; // aftershock damage
            cout << "aftershock proc dmg: " << aftershock << endl;
        }
        else if (alvl == 4){
            aftershock = 1.272 * weapon_dmg; // aftershock damage
            cout << "aftershock proc dmg: " << aftershock << endl;
        }
        cout << (dpm / 50000) << " procs" << endl;
        double ashock_damage = (dpm / 50000) * aftershock;
        cout << "total aftershock damage done: " << ashock_damage << endl;
        double aftershock_dmg_inc = (((dpm + ashock_damage) / dpm) - 1) * 100;
        cout << "damage increase: " << aftershock_dmg_inc << "%" << endl;
        dpm += ashock_damage;
    }
    
    cout << "final damage: " << dpm;
    cout << endl << endl;
    
    
    cout << "cumulative damage increase with p" << plvl << " a" << alvl << " e" << elvl << ": ";
    cout << ((dpm / dpm_dont_change) - 1) * 100 << "%" << endl;
}

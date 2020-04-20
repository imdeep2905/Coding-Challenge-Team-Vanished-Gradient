/**
 * 
 * REQUIRES >= C++11 for console output.
 *          >= python 3 (with matplotlib(>=3.1.2) and set as environment variable) for visualization.
 * ->Note that if python fulfills given requierment than visulization will automatically be shown.
 * ->Note that this code is for strategy 3. To change strategy you need to change codes in 
 *   is_beeter_depth or/and is_better_width. Or you can directly execute solution_strategy(1/2/3).exe.
 *  
 ********************************************************************************************
 * Solution for AIIE ICT Coding challenge                                                   *
 * Title : Heuristic Solution for KCLP (Knapsack Container loading problem)                 *
 *                                                                                          *
 *                              ***Authors***                                               *
 * Deep Raval      - Enrollment No: 171310132048, Email: deepraval.ict17@gmail.com          *
 * Jaymin Suhagiya - Enrollment No: 171310132056, Email: jayminsuhagiya.ict17@gmail.com     *   
 ********************************************************************************************
**/
#include <iostream>
#include <chrono> 
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <conio.h>
#define endl '\n'
#define FAST_IO ios::sync_with_stdio(0); std::cin.tie(0);
typedef long long ll;
using namespace std;
const ll N = 5; //Number of switches (fixed)
ll rack_height, rack_width, rack_depth;//rack dimenssions
vector <ll> switches_value(N), switches_inst(N);//Switches value and #of instances
vector < vector<ll> > switches_cord(N, vector<ll>(3));//Switches coordinates
vector <ll> depth_list, width_list;//Storing list of promising widths and depths
vector<ll> get_promising_widths()
{
    /*
    Purpose   : This function analyze switches coordinates and determine list of promising widths. 
    Arguments : None
    return    : 1D Vector containing promising widths.
    */
    ll avg = 0;
    for(ll i = 0 ; i < N ; i ++)
        for(ll j = 0; j < 3; j ++)
                avg += switches_cord[i][j];
    avg /= (double(N) * 3);
    vector <ll> list;
    list.push_back(rack_width);
    list.push_back(avg);
    avg = 0;
    for(ll i = 0 ; i < N ; i ++)
            avg += max({switches_cord[i][0], switches_cord[i][1], switches_cord[i][2]});
    avg /= N;
    list.push_back(avg);
        avg = 0;
    for(ll i = 0 ; i < N ; i ++)
            avg += min({switches_cord[i][0], switches_cord[i][1], switches_cord[i][2]});
    avg /= N;
    list.push_back(avg);
    for(ll i = 0 ; i < N ; i ++)
    {
        if(find(list.begin(), list.end(), switches_cord[i][0]) == list.end())
            list.push_back(switches_cord[i][0]);
        if(find(list.begin(), list.end(), switches_cord[i][1]) == list.end())
            list.push_back(switches_cord[i][1]);
        if(find(list.begin(), list.end(), switches_cord[i][2]) == list.end())
            list.push_back(switches_cord[i][2]);
    }
    sort(list.begin(), list.end(), greater<ll>());
    return list;
}
vector<ll> get_promising_depths()
{    
    /*
    Purpose   : This function analyze switches coordinates and determine list of promising depths. 
    Arguments : None
    return    : 1D Vector containing promising depths.
    */
    ll avg = 0;
    for(ll i = 0 ; i < N ; i ++)
        for(ll j = 0; j < 3; j ++)
                avg += switches_cord[i][j];
    avg /= (double(N) * 3);
    vector <ll> list;
    list.push_back(avg);
    avg = 0;
    for(ll i = 0 ; i < N ; i ++)
            avg += max({switches_cord[i][0], switches_cord[i][1], switches_cord[i][2]});
    avg /= N;
    list.push_back(avg);
        avg = 0;
    for(ll i = 0 ; i < N ; i ++)
            avg += min({switches_cord[i][0], switches_cord[i][1], switches_cord[i][2]});
    avg /= N;
    list.push_back(avg);
    for(ll i = 0 ; i < N ; i ++)
    {
        if(find(list.begin(), list.end(), switches_cord[i][0]) == list.end())
            list.push_back(switches_cord[i][0]);
        if(find(list.begin(), list.end(), switches_cord[i][1]) == list.end())
            list.push_back(switches_cord[i][1]);
        if(find(list.begin(), list.end(), switches_cord[i][2]) == list.end())
            list.push_back(switches_cord[i][2]);
    }
    sort(list.begin(), list.end(), greater<ll>());
    return list;
}
void take_input()
{
    /*
    Purpose   : This function takes input from user and store them in global variables and also this function
                converts given coordinates in required format. 
    Arguments : None 
    return    : None.
    */
    cout << "**********************************************************************************"<< endl;
    cout << "* Orientation not allowed. Pairing allowed."<< endl;
    cout << "* Solution with strategy 3 (Width: value||volume, Depth: value/volume)" << endl;
    cout << "* Input Format (Space seprated values)" << endl;
    cout << "* First Line : rack_length rack_breadth rack_height" << endl;
    cout << "* Next " << N <<" Lines: dim1(l) dim2(b) dim3(h) switch_value switch_instances"<< endl;
    cout << "**********************************************************************************"<< endl;
    cin >> rack_depth >> rack_width >> rack_height;
    if( rack_width >= rack_depth )
        swap(rack_depth, rack_width);
	for(ll i = 0; i < N; i++)
    {
        cin >> switches_cord[i][2] >> switches_cord[i][1] >> switches_cord[i][0] >> switches_value[i] >> switches_inst[i];
    }
    depth_list = get_promising_depths();//Getting all promising depths
    width_list = get_promising_widths();//Gets all promising widths.
}
bool is_better_depth(vector<vector<ll>> cur, vector<vector<ll>> lcl_best, vector<vector<ll>> best,ll d, ll db, ll dt)
{
    /*
    Purpose   : This function analyze given two solution and determine which is worth exploring further. 
    Arguments : cur: Currently obtained solution
                prev: Current best solution for some depth.
    return    : True or False.
    */

    // Comment first strategy to use second one.

    //Greater Value | Volume strategy
    //return cur[0][0] >= lcl_best[0][0] || cur[1][0] >= lcl_best[1][0];
    
    //Value per Volume strategy
    ///*
    if(db == 0)
        return cur[0][0] >= lcl_best[0][0];
    else 
       return double(cur[0][0] - best[0][0]) / (double(d) * rack_height * rack_width) >= double(lcl_best[0][0] - best[0][0]) / (double(db) * rack_height * rack_width);
    //*/
}
bool is_better_width(vector<vector<ll>> cur, vector<vector<ll>> lcl_best, vector<vector<ll>> best, ll d, ll w, ll wb, ll wt)
{
    /*
    Purpose   : This function analyse given two solution and determine which is worth exploring furthur. 
    Arguments : cur: Currently obtained solution
                prev: Current best solution for some width.
    return    : True or False.
    */

    // Comment first strategy to use second one.

    //Greater Value | Volume strategy
    return cur[0][0] >= lcl_best[0][0] || cur[1][0] >= lcl_best[1][0];
    
    //Value per Volume strategy
    ///*
    if(wb == 0)
        return cur[0][0] >= lcl_best[0][0];
    else 
        return double(cur[0][0] - best[0][0]) / (double(w) * rack_height * d) >= double(lcl_best[0][0] - best[0][0]) / (double(wb) * rack_height * d);
    //*/
}
bool pairing_compare(const pair<ll, ll> a, const pair<ll, ll> b)
{
    /*
    Purpose   : This function is passed in std::sort to sort the given pairs of switches according to
                summation of their widths. 
    Arguments : a: pair 1
                b: pair 2
    return    : True or False.
    */
    return (switches_cord[a.first][1] + switches_cord[a.second][1]) >= (switches_cord[b.first][1] + switches_cord[b.second][1]);
}
map<ll, pair<ll, ll> > try_pairing(ll w, vector<ll> &h, vector<ll> &v, vector<ll> &switches)
{  
    /*
    Purpose   : This function is passed in std::sort to sort the given pairs of switches according to
                summation of their widths. 
    Arguments : w: currently being considered width.
                    ---pass by ref---
                h: currently being considered switch's height.
                v: currently being considered switch's value
                s: currently being considered switches.
    return    : map to resolve the indexing of pairs.
    */
    ll index = N;
    vector < pair<ll, ll> > pairs;
    map <ll, pair<ll, ll> > resolver;
    for(ll i = 0; i < N; i ++)
    {
        for(ll j = i; j < N; j ++)
        {
            //Determining pairs of switches which can be paired.
            if(switches_cord[i][0] == switches_cord[j][0] && switches_cord[i][1] + switches_cord[j][1] <= w)
                pairs.push_back({i, j});
        }
    }
    set <ll> done;
    sort(pairs.begin(), pairs.end(), pairing_compare);
    for(pair<ll, ll> p : pairs)
    {
        if(!done.count(p.first) && !done.count(p.second))
        {
            resolver[index] = p;
            done.insert(p.first);
            done.insert(p.second);
            ll transfer =    count(switches.begin(), switches.end(), p.first) 
                                                <= 
                            count(switches.begin(), switches.end(), p.second) ?
                            count(switches.begin(), switches.end(), p.first) :
                            count(switches.begin(), switches.end(), p.second); 
            ll fi;
            for(ll i = 0 ; i < switches.size(); i ++)
                if(switches[i] == p.first)
                {
                    fi = i;
                    break;
                }  
            //Replacing/Deleting info of switches which were paired.
            switches.erase( switches.begin()+ fi, switches.begin() + fi + transfer);
            h.erase(h.begin() + fi, h.begin() + fi + transfer );
            v.erase(v.begin() + fi, v.begin() + fi + transfer );
            for(ll i = 0 ; i < switches.size(); i ++)
                if(switches[i] == p.second)
                {
                    fi = i;
                    break;
                }
            replace(switches.begin() + fi, switches.begin() + fi + transfer, p.second, index);
            replace(v.begin() + fi, v.begin() + fi + transfer, switches_value[p.second], switches_value[p.first] + switches_value[p.second]);            index ++;
        }
    }
    return resolver;
}
vector< vector <ll>> knapsack_fill(ll W, vector<ll> wt, vector<ll> val, ll n) 
{ 
    /*
    Purpose   : This function solves 1D knapsack problem using Dynamic Programming (Tabular Method). 
    Arguments : W: Bag weight(height of rack), 
                wt: weights of items(heights of switches), 
                val: Values of items(values of switches), 
                n : Total available switch.
    return    : 2D vector with value gained and chosen switches.
    */
    ll i, w; 
    vector < vector <ll> > K(n + 1, vector<ll>(W + 1, 0));//Table for solving knapsack
    vector< vector<ll>> Knapsack_result;
    vector<ll> switch_selected;
    //Tabular method.
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] +  K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
    // stores the result of Knapsack 
    ll res = K[n][W];     
    Knapsack_result.push_back(vector<ll>(1, res));
    w = W; 
    //Finding switches which are selected.
    for (i = n; i > 0 && res > 0; i--) {  
        if (res == K[i - 1][w])  
            continue;         
        else { 
  
            switch_selected.push_back(i-1);
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
        } 
    }
    for(ll x : switch_selected)
        if(x>=N)
        {
            sort(switch_selected.begin(), switch_selected.end(), greater<ll>());
            Knapsack_result.push_back(switch_selected);
            return Knapsack_result;
        }
    reverse(switch_selected.begin(), switch_selected.end());
    Knapsack_result.push_back(switch_selected);
    return Knapsack_result;    
} 
vector< vector <ll> > fill_stride(ll x, ll y, ll d, ll w, vector < vector<ll> > prev_sol)
{
    /*
    Purpose :   This function solves knapsack problem for perticular depth, width 
                and available switches.(In other words this function convert 2D
                knapsack to 1D knapsack and also solve it).
    Arguments : x: x coordinate, 
                y: y coordinate, 
                d: Currently considered Depth, 
                W:Currently considered Width, 
                prev_sol: Best Solution at previous level of tree
    return: previous result which contains
            Current value,
            Filled volume,
            remaining switches,
            [Switch type, orientation, coordinates]
    */
    vector< vector <ll>> knapsack_return = {{}, {}, {}};
    vector <ll> available_switch = prev_sol[2], switch_pool_h, switch_pool_v, switch_taken;
    for(ll i = 0 ;i < N ; i ++)
    {
        if(switches_cord[i][1] <= w && switches_cord[i][2] <= d)
            for(ll j = 0 ; j < available_switch[i]; j ++)
            {
                switch_pool_h.push_back(switches_cord[i][0]);//vector which contain heights of all available switches
                switch_pool_v.push_back(switches_value[i]);//vector which contain value of all available switches
                switch_taken.push_back(i);
            } 
    }
    map <ll, pair<ll, ll> > resolve_pairing =  try_pairing(w, switch_pool_h, switch_pool_v, switch_taken);
    knapsack_return = knapsack_fill(rack_height, switch_pool_h, switch_pool_v, switch_pool_h.size());//knapsack call
    prev_sol[0][0] += knapsack_return[0][0];
    ll volume = 0;
    ll h = 0;
    //append volume, value, and coordinates of switches in prev_sol.
    for(ll i = 0; i < knapsack_return[1].size(); i ++)
    {
        if(switch_taken[knapsack_return[1][i]] < N)
        {
            //Adding volume of switches one by one.
            volume +=   switches_cord[switch_taken[knapsack_return[1][i]]][0] * 
                        switches_cord[switch_taken[knapsack_return[1][i]]][1] * 
                        switches_cord[switch_taken[knapsack_return[1][i]]][2];
            //Remove the used switches one by one.
            --available_switch[switch_taken[knapsack_return[1][i]]]; 
            //Storing switch type.
            prev_sol[3].push_back(switch_taken[knapsack_return[1][i]]);
            //Storing Orientation of switch.
            prev_sol[3].push_back(switches_cord[switch_taken[knapsack_return[1][i]]][0]); 
            prev_sol[3].push_back(switches_cord[switch_taken[knapsack_return[1][i]]][1]);
            prev_sol[3].push_back(switches_cord[switch_taken[knapsack_return[1][i]]][2]);
            //Storing Actual coordinates of placed switch.
            prev_sol[3].push_back(x);
            prev_sol[3].push_back(y);
            prev_sol[3].push_back(h);
            //Increasing Z coordinate.
            h += switches_cord[switch_taken[knapsack_return[1][i]]][0];
        }
        else 
        {
            pair <ll, ll> p =  resolve_pairing[switch_taken[knapsack_return[1][i]]]; 
            ll f = p.first;
            ll s = p.second;
            volume +=   switches_cord[f][0] * 
                        switches_cord[f][1] * 
                        switches_cord[f][2];
            volume +=   switches_cord[s][0] * 
                        switches_cord[s][1] * 
                        switches_cord[s][2];
            
            --available_switch[f];--available_switch[s];
            
            prev_sol[3].push_back(f);
            prev_sol[3].push_back(switches_cord[f][0]); 
            prev_sol[3].push_back(switches_cord[f][1]);
            prev_sol[3].push_back(switches_cord[f][2]);
            prev_sol[3].push_back(x);
            prev_sol[3].push_back(y);
            prev_sol[3].push_back(h);
            
            prev_sol[3].push_back(s);
            prev_sol[3].push_back(switches_cord[s][0]); 
            prev_sol[3].push_back(switches_cord[s][1]);
            prev_sol[3].push_back(switches_cord[s][2]);
            prev_sol[3].push_back(x );
            prev_sol[3].push_back(y + switches_cord[f][1]  );
            prev_sol[3].push_back(h);

            h += switches_cord[f][0];
        }
    }   
    //Combining current solution with previous solution
    prev_sol[1][0] += volume;
    prev_sol[2] = available_switch;
    return prev_sol;
}
vector< vector <ll> > fill_depth(ll x, ll d, vector <vector <ll> > prev_sol)
{
    /*
    Purpose    :  This function is called for individual depth.For each depth it calls fill_stripe for each promising
                  width and only explores most promising width(Similar to test_case).Finally it returns best solution
                  possible with current depth.
    Arguments  :  x: Currently considered X coordinate
                  d: Currently considered depth
                  prev_sol: Best solution at previous level of the tree
    Return     :  2D Vector returning soluion with current depth (Combined with prev_sol)
    */
    ll width_remaining = rack_width, best_width = 0, width_track = 0;//Tracking remaining width, best width and current width.
    vector < vector<ll> >  best_solution = prev_sol, best_local_solution = prev_sol, tmp; // To store results from fill depth
    bool called = true;        
    while(called)
    {    
        called = false;
        best_local_solution = best_solution;
        for(ll i = 0; i < width_list.size(); i ++)
        {
            if(width_remaining - width_list[i] >= 0)
            {
                called = true;
                tmp = fill_stride(x, width_track, d, width_list[i], best_solution);//Filling rack with H * current_width * current_depth
                if(is_better_width(tmp, best_local_solution, best_solution, x, width_list[i], best_width, width_track))//If current solution looks promising choose it to explore furthur.
                {    
                    best_local_solution = tmp;
                    best_width = width_list[i];
                }
            }
        }
        best_solution = best_local_solution;
        width_track += best_width;
        width_remaining -= best_width;
    }
    return best_solution;
}
void solve_KCLP()
{
    /*
    Purpose    :  This is the main crust of our program.It choses depth and calls fill_depth recursively. After filling whole
                  rack with help of smaller depths, It prints all necessary information about solution.
    Arguments  :  None
    Return     :  None
    */
    take_input();// Getting input as well as setting up them in global variables.
    auto start = chrono::high_resolution_clock::now();//Starting clock
    // Calling fill_depth function recursively (only through the path which looks most promising)
    /*
    (For ex if 3rd depth gives best result then only that node is explored furthur and so on)
    1   2     3    4    5
    X   X   //|\\  X    X
              .
              .
              .
    */
    vector < vector<ll> >  best_solution = {{0},{0}, switches_inst, {}}, best_local_solution = {{0},{0}, switches_inst, {}}, tmp; // To store results from fill_depth function
    // Solution format (2D Vector) : Current value, Current volume, Remaining Switches, [Switch type, orientation, coordinates]* 
    ll depth_remaining = rack_depth, best_depth = 0, depth_track = 0;//To track remaining depth, current best depth and filled depth
    bool called = true;  
    //Starting main loop. We'll loop untill we can't take any depth due to unavialable space.      
    while(called)
    {    
        called = false;
        best_local_solution = best_solution;
        for(ll i = 0; i < depth_list.size(); i ++)
        {
            if(depth_remaining - depth_list[i] >= 0)
            {
                called = true;
                tmp = fill_depth(depth_track, depth_list[i], best_solution);//Filling rack with dimenssion H * W * current_depth
                if(is_better_depth(tmp, best_local_solution, best_solution, depth_list[i], best_depth, depth_track))//If current solution looks promising choose it to explore furthur.
                {    
                    best_local_solution = tmp;
                    best_depth = depth_list[i];
                }
            }
        }
        best_solution = best_local_solution;
        depth_track += best_depth;
        depth_remaining -= best_depth;
    }
    auto stop = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);//Calculating execution time
    /*  ***OUTPUT OF THE PROGRAM GETS PRINTED HERE***   */
    cout << "\n   ***SUMMARY OF PLACED SWITCHES***" <<endl;
    cout << "Sr.\tTYPE\tORIENTATION\tPOSITION\n";
    for(ll i = 0, j = 1; i < best_solution[3].size(); i+=7, j ++)
    {
        printf("%d.\t%d\t(%d, %d, %d)\t(%d, %d, %d)\n",
        j, 
        best_solution[3][i],
        best_solution[3][i + 1],
        best_solution[3][i + 2],
        best_solution[3][i + 3],
        best_solution[3][i + 4],
        best_solution[3][i + 5],
        best_solution[3][i + 6]);
    }
    cout <<"\nExecution Completed in: "<<  duration.count() / 1e6 << " Seconds"<< endl; 
    printf("Format for coordinates : (height, width, depth)\n");
    printf("See rack dimenssion as : (%d, %d, %d)\n",rack_height, rack_width, rack_depth);
    cout << "Remaining Switches: ";
    for(ll x : best_solution[2])
        cout << x <<' ';
    cout << endl;
    cout << "Total Value gained: " << best_solution[0][0] <<endl;
    cout << "% of total volume packed: " << ( best_solution[1][0] / (double(rack_height) * rack_width * rack_depth) )* 100<<" %"<<endl;
    if( count(best_solution[2].begin(), best_solution[2].end(), 0) == N 
                            &&
        ( best_solution[1][0] / (double(rack_height) * rack_width * rack_depth) )* 100 != 100 )
    {
        cout <<"*** This Test Case is INVALID as per clg's assumption ! ***" << endl;
    }
    //Creating file "output.txt" for visualization purpose
    ofstream o;
    o.open("output.txt", ofstream::out | ofstream::trunc);
    o << rack_height <<' '<<rack_width<< ' ' << rack_depth<< ' ' << endl;
    for(ll i = 0; i < best_solution[3].size(); i+=7)
    {
        o << best_solution[3][i] << ' ';
        o << best_solution[3][i + 1] << ' ';
        o << best_solution[3][i + 2] << ' ';
        o << best_solution[3][i + 3] << ' ';
        o << best_solution[3][i + 4] << ' ';
        o << best_solution[3][i + 5] << ' ';
        o << best_solution[3][i + 6] << ' ';
        o << endl;
    }
    o.close();
    system("python visualize.py");//Automatically executing python script to visualize it.
    return ;
}
int main()
{
    int t = 1;
    //cin >> t; //Uncomment for multiple test cases
    while(t --) 
        solve_KCLP();
    cout << "\nPress any key to exit...";
    getch();
    return 0;
}

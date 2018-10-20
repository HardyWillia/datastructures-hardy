/*

    Willia Hardy
    wjh26@zips.uakron.edu
    2905326
    Project2
*/

#ifndef EMPMAPS_H_INCLUDED
#define EMPMAPS_H_INCLUDED

#include "Employee.h"
#include <vector>
#include <unordered_map>
#include <map>


using std::vector;
using std::map;
using std::unordered_map;



vector<Employee> employees();
map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp);
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);
void printSalRange(map<int,vector<Employee>> & salRange);
unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp);
void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);

#endif // EMPMAPS_H_INCLUDED
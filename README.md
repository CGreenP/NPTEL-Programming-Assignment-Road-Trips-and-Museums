# NPTEL-Programming-Assignment-Road-Trips-and-Museums
NPTEL Programming Assignment: Road Trips and Museums.

# Road Trips and Museums
Lavanya and Nikhil have _K_ months of holidays ahead of them, and they want to go on exactly _K_ road trips, one a month. They have a map of the various cities in the world with the roads that connect them. There are _N_ cities, numbered from 1 to _N_. We say that you can reach city B from city A if there is a sequence of roads that starts from city A and ends at city B. Note that the roads are bidirectional. Hence, if you can reach city B from city A, you can also reach city A from city B.

Lavanya first decides which city to start from. In the first month, they will start from that city, and they will visit every city that they can reach by road from that particular city, even if it means that they have to pass through cities that they have already visited previously. Then, at the beginning of the second month, Nikhil picks a city that they haven't visited till then. In the second month, they first fly to that city and visit all the cities that they can reach from that city by road. Then, in the third month, Lavanya identifies a city, and they fly there and visit all cities reachable from there by road. Then in the fourth month it is Nikhil's turn to choose an unvisited city to start a road trip, and they alternate like this. Note that the city that they fly to (that is, the city from where they start each month's road trip) is also considered as being visited.

Each city has some museums, and when they visit a city for the first time, Lavanya makes them visit each of the museums there. Lavanya loves going to museums, but Nikhil hates them. Lavanya always makes her decisions so that they visit the maximum number of museums possible that month, while Nikhil picks cities so that the number of museums visited that month is minimized.

Given a map of the roads, the number of museums in each city, and the number _K_, find the total number of museums that they will end up visiting at the end of _K_ months. Print -1 if they will have visited all the cities before the beginning of the _K_ <sup>th</sup> month, and hence they will be left bored at home for some of the _K_ months.

# Solution hint
Use BFS/DFS to identify the connected components of the underlying undirected graph. Sort the components based on how many museums they contain and make appropriate choices for Lavanya and Nikhil each month.

# Input format
* The first line of each testcase contains three integers: _N_, _M_ and _K_, which represents the number of cities, number of roads and the number of months.
* The i<sup>th</sup> of the next _M_ lines contains two integers, _u<sub>i</sub>_ and _v<sub>i</sub>_. This denotes that there is a direct road between city _u<sub>i</sub>_ and city _v<sub>i</sub>_.
* The next line contains _N_ integers, the ith of which represents the number of museums in city i.

# Output format
If they can go on _K_ road trips, output a single line containing a single integer which should be the total number of museums they visit in the _K_ months. Output -1 if they can't go on _K_ road trips.

# Constraints
* 1 ≤ _T_ ≤ 3
* 1 ≤ _N_ ≤ 10<sup>6</sup>
* 0 ≤ _M_ ≤ 10<sup>6</sup>
* 1 ≤ _K_ ≤ 10<sup>6</sup>
* 1 ≤ _u<sub>i</sub>_, _v<sub>i</sub>_ ≤ _N_
* There is no road which goes from one city to itself. ie. _u<sub>i</sub> ≠ v<sub>i</sub>_.
* There is at most one direct road between a pair of cities.
* 0 ≤ Number of museums in each city ≤ 1000
* Sum of _N_ over all testcases in a file will be ≤ 1.5 * 10<sup>6</sup>

# Sample input 1
```sh
10 10 3
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
```

# Sample output 1
```sh
345
```

# Sample input 2
```sh
10 10 2
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
```

# Sample output 2
```sh
240
```

# Sample input 3
```sh
10 10 5
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
```

# Sample output 3
```sh
-1
```

# Explanation
Notice that in all the three testcases, everything is the same, except for the value of _K_. The following figure represents the road map in these testcases. Each node denotes a city, with a label of the form "n (m)", where n is the city number, between 1 and _N_, and m is the number of museums in this city. For example, the node with label "5 (25)" represents city 5, which has 25 museums.
<p align="center">
  <img src="https://github.com/CGreenP/NPTEL-Programming-Assignment-Road-Trips-and-Museums/assets/56307530/4827558e-1061-443a-9ade-a969d9e97a5d" />
</p>

_Testcase 1_: Lavanya will first choose to fly to city 8. In the first month, they visit only that city, but they visit 150 museums.

Then in the second month, Nikhil could choose to fly to city 3, and they visit the cities 1, 2, 3, 5 and 6, and visit 20 + 0 + 15 + 25 + 30 = 90 museums that month. Note that Nikhil could have instead chosen to fly to city 1 or 2 or 5 or 6, and they would all result in the same scenario.

Then, Lavanya could choose city 7, and in the third month they will visit the cities 7, 4, 10 and 9. Note that Lavanya could have chosen to fly to city 4 or 10 or 9, and they would all result in the same scenario.

In total, they have visited 345 museums in the three months (which is in fact all the museums), and that is the answer.

_Testcase 2_: It is same as the previous testcase, but now they have only 2 months. So they visit only 150 + 90 = 240 museums in total.

_Testcase 3_: It is same as the previous testcase, but now they have 5 months of holidays. But sadly, they finish visiting all the cities within the first three months itself, and hence the answer is -1.

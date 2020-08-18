flightPath(lax,nrt,12,5439). 
flightPath(cdg,lax,12,5656). 
flightPath(cdg,jfk ,8,3624). 
flightPath(cdg,fco, 2,684). 
flightPath(lju,cdg, 2,587). 
flightPath(lju,fco,1,265). 
flightPath(jfk,lax,7,2469). 
flightPath(fco,jfk,10,4266). 
flightPath(fco,sin,12,6245). 
flightPath(sin,nrt,7,3329). 
flightPath(jfk,nrt,14,6729). 
transferTime(lax, 1). 
transferTime(jfk, 1). 
transferTime(fco, 2). 
transferTime(cdg, 1). 
transferTime(lju, 2). 
transferTime(sin, 2). 
transferTime(nrt, 3). 

connection(Start,Destination):- flightPath(Start,Destination,_,_).  
connection(Start,Destination):- flightPath(Start,Indirect,_,_), connection(Indirect,Destination). 

flightTime(Start,Destination,Time,[Start,Destination]) :- flightPath(Start,Destination,Time,_).
flightTime(Start,Destination,Time,[Start|Path]):- flightPath(Start,Indirect,T1,_),
                     flightTime(Indirect,Destination,T2,Path),transferTime(Indirect,T3),
                     Time is T1 + T2 + T3.

pathLength([Start,Destination],Length):- flightTime(Start,Destination,_,[Start,Destination]),
                                       flightPath(Start,Destination,_,Length).
pathLength([Start,Destination|Path],Length):- flightTime(Start,Destination,_,[Start,Destination]),
                           flightPath(Start,Destination,_,L1),
                           pathLength([Destination|Path],L2), Length is L1 + L2.

shortestPath(Start,Destination):- findall(Length,(flightTime(Start,Destination,_,Path),pathLength(Path,Length)),List),
                             min_list(List,Length),
                             pathLength(Path,Length),
                             print(Path).

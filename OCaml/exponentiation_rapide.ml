let rec expo_rapide n p = match p with
| 0 -> 1
| k when k mod 2 = 0 -> let m = (expo_rapide n (p/2)) in m*m
| _ -> let m = (expo_rapide n (p/2)) in n*m*m;;

expo_rapide 5 10;;
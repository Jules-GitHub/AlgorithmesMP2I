let rec decomposition n base = match n with
| k when k<base -> [k]
| _ -> (n mod base)::(decomposition (n/base) base);;

let rec calcul l base = match l with
| [] -> 0
| t::q -> t + (calcul q base)*base;;

calcul (decomposition 1005 8) 8;;


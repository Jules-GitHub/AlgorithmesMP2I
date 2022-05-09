let divise liste pivot = List.partition (fun x -> x <= pivot) liste;;

let rec tri_rapide liste = match liste with
| [] -> []
| [x] -> [x]
| _ -> let pivot = List.hd liste in
  let l1, l2 = divise (List.tl liste) pivot in
  let liste1, liste2 = tri_rapide l1, tri_rapide l2 in
  liste1@(pivot::liste2)
;;

let l = [2; 8; 6; 9; 4; 7; 1; 3; 5];;

divise l (List.hd l);;

tri_rapide l;;
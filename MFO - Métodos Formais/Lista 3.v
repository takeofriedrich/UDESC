(* Nome:  Vinícius Takeo Friedrich Kuwaki*)

(* Todas as declarações devem ser feitas nesse arquivo,
   não deve ser importado nenhum módulo adicional. *)

Require Import PeanoNat.

Inductive list (X:Type) : Type :=
  | nil
  | cons (x : X) (l : list X).

Arguments nil {X}.
Arguments cons {X} _ _.

Fixpoint app {X : Type} (l1 l2 : list X)
             : (list X) :=
  match l1 with
  | nil      => l2
  | cons h t => cons h (app t l2)
  end.

Notation "x :: y" := (cons x y)
                     (at level 60, right associativity).
Notation "[ ]" := nil.
Notation "[ x ; .. ; y ]" := (cons x .. (cons y []) ..).
Notation "x ++ y" := (app x y)
                     (at level 60, right associativity).

Fixpoint length {X : Type} (l : list X) : nat :=
  match l with
  | [] => 0
  |  _ :: l' => S (length l')
  end.

Fixpoint rev {X:Type} (l:list X) : list X :=
  match l with
  | nil      => nil
  | cons h t => app (rev t) (cons h nil)
  end.

Fixpoint index {X : Set} (n : nat) (l : list X) : option X :=
  match l with
  | [] => None
  | h :: t => if n =? 0 then Some h else index (pred n) t
  end. 

Fixpoint map {X Y: Type} (f:X->Y) (l:list X) : (list Y) :=
  match l with
  | []     => []
  | h :: t => (f h) :: (map f t)
  end.

Fixpoint repeat {X : Type} (x : X) (count : nat) : list X :=
  match count with
  | 0        => nil
  | S count' => cons x (repeat x count')
  end.

Fixpoint fold {X Y: Type} (f: X->Y->Y) (l: list X) (b: Y)
                         : Y :=
  match l with
  | nil => b
  | h :: t => f h (fold f t b)
  end.

Theorem app_nil_l : forall {X:Type} (l:list X),
  [] ++ l = l.
Proof. reflexivity. Qed.

Theorem app_nil_r : forall (X:Type) (l : list X),
  l ++ [] = l.
Proof.
  intros X l. induction l.
  reflexivity. simpl. rewrite IHl. reflexivity.
Qed.

(* Questão 1: Prove o teorema abaixo: *)

Compute (repeat 3 4).

Theorem repeat_n : forall {X:Set} (n:nat) (x:X),
  length (repeat x n) = n.
Proof. 
  intros X n x. induction n as [| n' ].
  -reflexivity.
  -simpl. rewrite IHn'. reflexivity.
Qed.
  
(* Questão 2: A operação reverso de uma lista ([rev]) é distributiva em relação 
    a concatenação, prove esse teorema. *)

Theorem app_assoc : forall { A: Type } (l m n:list A),
  l ++ m ++ n = (l ++ m) ++ n.
Proof.
  intros A l m n. induction l.
  - simpl. reflexivity.
  - simpl. rewrite IHl. reflexivity.
Qed.

Theorem rev_app_distr: forall X (l1 l2 : list X),
  rev (l1 ++ l2) = rev l2 ++ rev l1.
Proof.
  intros X l1 l2. induction l1 as [| l1'].
  - simpl. rewrite app_nil_r. reflexivity.
  - simpl. rewrite IHl1. simpl. rewrite app_assoc. reflexivity.
Qed.

(* Questão 4: *) 

Theorem index_map : forall {X Y:Set} (n:nat) (f:X->Y) (l:list X) (x:X), 
  index n l = Some x -> Some (f x) = index n (map f l).
Proof.
  intros X Y n f. induction n as [| n' IH].
  - intros l x H1. destruct l as [| h t].
    + discriminate H1.
    + simpl in H1. injection H1 as H1'. simpl. rewrite H1'. reflexivity.
  - intros. induction l.
    + simpl. discriminate.
    + simpl. simpl in H. apply IH. apply H.
Qed.


(* Questão 5: *)

Theorem len_index_none : forall {X : Set} (n : nat) (l : list X), 
  length l = n -> index n l = None.
Proof.
   intros. generalize dependent n; induction l as [| x l'];
   intros n H; destruct n as [| n']; inversion H as [H1]; clear H1.
  - reflexivity. 
  - simpl; apply IHl'; reflexivity. Qed.
  
(* Questão 6: Informalmente podemos dizer, a função [fold] é comutativa em 
    relação a concatenação ([++]), prove esse teorema. *)
  
Theorem app_comm_fold :forall {X Y} (f: X->Y->Y) l1 l2 b,
  fold f (l1 ++ l2) b = fold f l1 (fold f l2 b).
Proof.
  intros X Y f l1 l2 b. induction l1 as [| x l1'].
  - simpl. reflexivity. 
  - simpl. rewrite IHl1'. reflexivity.
Qed.


(* Questão 7: Defina uma versão da função map usando a função fold. *)

Definition map' {X Y: Type} (f:X->Y) (l:list X) : (list Y) :=
  fold (fun x t => f x::t) l []. 

(* Questão 8: A função [prod_curry] transforma uma função binária currificada em
   uma função não currificada, que recebe um único argumento do tipo produto,
   defina uma função [prod_uncurry] que faça o processo inverso. *)

Definition prod_curry {X Y Z : Type}
  (f : X * Y -> Z) (x : X) (y : Y) : Z := f (x, y).


Definition prod_uncurry {X Y Z : Type}
  (f : X -> Y -> Z) (p : X * Y) : Z :=
  f (fst p) (snd p).

(* Questão 9: Prove que a função [prod_curry] reverte a aplicação de [prod_uncurry]. *)

Theorem uncurry_curry : forall (X Y Z : Type)
                        (f : X -> Y -> Z)
                        x y,
  prod_curry (prod_uncurry f) x y = f x y.
Proof.
  reflexivity.

    
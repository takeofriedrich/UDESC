Require Import PeanoNat.

(* Todas as definições necessárias devem ser declaradas nesse arquivo *)

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

Fixpoint map {X Y: Type} (f:X->Y) (l:list X) : (list Y) :=
  match l with
  | []     => []
  | h :: t => (f h) :: (map f t)
  end.


Fixpoint All {T : Type} (P : T -> Prop) (l : list T) : Prop :=
  match l with
  | [] => True
  | (h :: t) => P h /\ All P t 
  end.

Fixpoint In {A : Type} (x : A) (l : list A) : Prop :=
  match l with
  | [] => False
  | x' :: l' => x' = x \/ In x l'
  end.


Theorem or_distributes_over_and : forall P Q R : Prop,
  P \/ (Q /\ R) <-> (P \/ Q) /\ (P \/ R).
Proof.
  intros P Q R. unfold iff. split.
  - intros. split. destruct H.
  * left. apply H.
  * destruct H as [HQ HR]. right. apply HQ.
  * destruct H. left. apply H. destruct H. right. apply H0.
  - intros. destruct H. destruct H.
  * left. apply H.
  * destruct H0. left. apply H0. right. split. apply H. apply H0.
Qed.

Theorem dist_exists_and : forall (X:Type) (P Q : X -> Prop),
  (exists x, P x /\ Q x) -> (exists x, P x) /\ (exists x, Q x).
Proof.
  intros. destruct H. destruct H. split.
  + exists x. apply H.
  + exists x. apply H0.
Qed.

Lemma In_map_iff :
  forall (A B : Type) (f : A -> B) (l : list A) (y : B),
    In y (map f l) <->
    exists x, f x = y /\ In x l.
Proof.
  intros A B f l y.
  unfold iff.
  split.
  - induction l as [|x' l' Hl'].
    + simpl. intros [].
    + simpl. intros [H | H].
      * exists x'. split. apply H. left. reflexivity.
      * apply Hl' in H. destruct H as [x [H1 H2]]. exists x. split. apply H1. right. apply H2.
  - induction l as [|x' l' Hl'].
    + simpl. intros [x [H1 []]].
    + simpl. intros [x [H1 [H2 | H2]]].
      * left. rewrite -> H2. apply H1.
      * right. assert (H' : exists x: A, f x = y /\ In x l'). exists x. split. apply H1. apply H2.
      apply Hl' in H'. apply H'.
Qed.

Lemma or_assoc :
  forall P Q R : Prop, P \/ (Q \/ R) <-> (P \/ Q) \/ R.
Proof.
  intros P Q R. split.
  - intros [H | [H | H]].
    + left. left. apply H.
    + left. right. apply H.
    + right. apply H.
  - intros [[H | H] | H].
    + left. apply H.
    + right. left. apply H.
    + right. right. apply H.
Qed.


Lemma In_app_iff : forall A l l' (a:A),
  In a (l++l') <-> In a l \/ In a l'.
Proof.
  intros A l l' a.
  unfold iff.
  split.
  - induction l as [|x' l'' Hl'].
    + simpl. intros H. right. apply H.
    + simpl. rewrite <- or_assoc. intros [H | H].
      * left. apply H.
      * right. apply Hl' in H. apply H.
  - induction l as [|x' l'' Hl'].
    + simpl. intros [H | H].
      * destruct H.
      * apply H.
    + simpl. rewrite <- or_assoc. intros [H | H].
      * left. apply H.
      * right. apply Hl' in H. apply H.
Qed.


Lemma All_In :
  forall T (P : T -> Prop) (l : list T),
    (forall x, In x l -> P x) <->
    All P l.
Proof.
  intros. unfold iff. split.
  + induction l.
  * intros. simpl. reflexivity.
  * intros. simpl. split. apply H. simpl. left. reflexivity. apply  IHl. intros. apply H. simpl. right. apply H0.
  + induction l as [|x' l' Hl'].
    * simpl. intros H1 H2 [].
    * simpl. intros [H1 H2] x [H3 | H3].
      - rewrite <- H3. apply H1.
      - apply Hl'. apply H2. apply H3.
Qed.
  


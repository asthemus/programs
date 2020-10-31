(clear-all)

(define-model semantic

(sgp :esc t :lf .05)

(chunk-type property object attribute value)
(chunk-type is-member object category judgment)

(add-dm
 (pets)(cats)(dogs)(unicorns)(siamese)(persian)(sphynx)
 (poodle)(bulldog)(dalmatian)(labrador)(pegasus)(rainbow)(narwhal)
 (true) (false) 
 
 
 
 (p1 ISA property object poodle attribute category value dogs)
 
 (p2 ISA property object bulldog attribute category value dogs)
(p3 ISA property object dalmatian attribute category value dogs)


 (p4 ISA property object rainbow attribute category value unicorns)

 (p5 ISA property object narwhal attribute category value unicorns)

 
(p7 ISA property object cats attribute category value pets)
 
 (p8 ISA property object dogs attribute category value pets)
 
 (p9 ISA property object unicorns attribute category value pets)
 
 (p10 ISA property object siamese attribute category value cats)
 
 (p11 ISA property object persian attribute category value cats)
 
 (p12 ISA property object sphynx attribute category value cats)
 
 
 (p13 ISA property object labrador attribute category value dogs)
 
 (p14 ISA property object pegasus attribute category value unicorns)

 
 
 (g1 ISA is-member object cats category pets)
 (g2 ISA is-member object pegasus category unicorns)
 (g3 ISA is-member object bulldog category cats))

(p initial-retrieve
   =goal>
      ISA         is-member
      object      =obj
      category    =cat
      judgment    nil
==>
   =goal>
      judgment    pending
   +retrieval>  
      ISA         property
      object      =obj
      attribute   category
)


(P direct-verify
   =goal>
      ISA         is-member
      object      =obj
      category    =cat
      judgment    pending
   =retrieval>
      ISA         property
      object      =obj
      attribute   category
      value       =cat
==>
   =goal>
      judgment    yes
   !output!       YES
)

(P chain-category
   =goal>
      ISA         is-member
      object      =obj1
      category    =cat
      judgment    pending
   =retrieval>
      ISA         property
      object      =obj1
      attribute   category
      value       =obj2
    - value       =cat
==>
   =goal>
      object      =obj2
   +retrieval>  
      ISA         property
      object      =obj2
      attribute   category
)

(P fail
   =goal>
      ISA         is-member
      object      =obj1
      category    =cat  
      judgment    pending
    
   ?retrieval>
      buffer      failure
==>
   =goal>
      judgment    no
   !output!       NO
	
)


(goal-focus g1)
)

swap : swap les deux data des deux derniers en partant de stackA

rotate : juste deplacer le pointer stackA vers le prochain ou le precedent

push : 
	1. top de B	---> next --> target (top A)
	2. bottom B ---> previous --> target
	3. previous de target ---> next --> bottom A
	4. bottom A ---> previous --> previous de target	
	5. target ---> next --> bottom B
	6. target ---> previous --> top B

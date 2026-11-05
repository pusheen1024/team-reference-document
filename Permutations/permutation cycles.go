for i := 0; i < n; i++ {
	if !used[i]
		x := i
		cycle := 0
		for !used[x]
			used[x] = true
			x = p[x]
			cycle++
}

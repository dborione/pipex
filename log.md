CYCLE 1

CMD 1
	- ** dat.env_paths = tabs malloc **split**
	  	-->fail: quit fork and
					 go to cmd2
	- ** dat.cmd_full = [cmd][param][param] **split**
		-->fail: free env_path,
					quit fork,
					go cmd2
		-> data.full[0] = cmd
			data.full[i] = param
		- data.full[0] = **strjoin** '/' + cmd
			-->fail: free env_path
						free cmd_full
						go cmd2
					
		

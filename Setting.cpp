set nu
set history=1000

set tabstop=4
set shiftwidth=4
set smarttab

set cindent

colo evening

set nobackup
set noswapfile

set mouse=a
map <C-A> ggVG"+y
map <F5> :call CR()<CR>
func! CR()
	exec "w"
	exec "!g++ % -g -O3 -std=c++11 -o %<"
	exec "!time ./%<"
endfunc
map<F6> :w<cr>:!python %<cr>


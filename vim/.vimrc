"jibancanyang's .vimrc

"基本配置
set transparency=30 "透明度
set background=dark 
syntax on
syntax enable
set mouse=a
set mousehide
set encoding=utf-8
scriptencoding utf-8
set backup "undo?
"inoremap { {<CR>}<ESC>O
"花括号匹配相关
inoremap { {}<ESC>i
inoremap {<CR> {<CR>}<ESC>O
set cursorline "高亮当前行
set number "行数
set autoindent "自动缩进
set smartindent "智能缩进
set cindent "C系列缩进
set softtabstop=4 "缩进长度
set shiftwidth=4 "缩进长度
set tabstop=4 "tab键长度
set expandtab "tab设为空格
set softtabstop=4 "缩进长度
colorscheme desert "配色沙漠 还有: torte, solarized, molokai, phd, ron, evening  等经典配色
set showmatch "自动匹配
set ruler "在右下角显示当前行信息
set incsearch "搜索加强
set hlsearch "搜索高亮
set guioptions-=T "一出工具栏
set showcmd "显示出输入的命令
set guifont=Menlo:h16 "字体和大小
set lines=55
set columns=178
set whichwrap=b,s,<,>,[,] " 光标从行首和行末时可以跳到另一行去
set scrolloff=3 "光标移动到上下两端,保持3行距离
set history=1000 "历史记录条数从20到1000
set autowrite "自动保存
set guioptions-=m "隐藏菜单栏
set ignorecase "搜索忽略大小写
filetype plugin indent on "自动检测文件类型并启动相关缩进插件
filetype plugin on "不同文件类型加载相应插件
filetype on "检查文件类型
set cmdheight=2 "命令行高度加1
" 让配置变更立即生效
autocmd BufWritePost $MYVIMRC source $MYVIMRC
" 关闭兼容模式
"set nocompatible
" vim 自身命令行模式智能补全
set wildmenu
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/.ycm_extra_conf.py' "YCM设置


"自定义一些快捷键
let mapleader=";" "自定义前缀键
" 定义快捷键到行首和行尾
nmap LB 0
nmap LE $
" 设置快捷键将选中文本块复制至系统剪贴板
vnoremap <Leader>y "+y
" 设置快捷键将系统剪贴板内容粘贴至 vim
nmap <Leader>p "+p
" 定义快捷键关闭当前分割窗口
nmap <Leader>q :q<CR>
" 定义快捷键保存当前窗口内容
nmap <Leader>w :w<CR>
" 定义快捷键保存所有窗口内容并退出 vim
nmap <Leader>WQ :wa<CR>:q<CR>
" 不做任何保存，直接退出 vim
nmap <Leader>Q :qa!<CR>
" 依次遍历子窗口
nnoremap nw <C-W><C-W>
" 跳转至右方的窗口
nnoremap <Leader>lw <C-W>l
" 跳转至左方的窗口
nnoremap <Leader>hw <C-W>h
" 跳转至上方的子窗口
nnoremap <Leader>kw <C-W>k
" 跳转至下方的子窗口
nnoremap <Leader>jw <C-W>j
" 定义快捷键在结对符之间跳转
nmap <Leader>M %


"自动生成代码设置
if !exists("*SetTitlea")
map <F2> :call SetTitlea()<CR>
func SetTitlea()
let l = 0
let l = l + 1 | call setline(l,'/**********************jibancanyang**************************')
let l = l + 1 | call setline(l,' *Author        :jibancanyang')
let l = l + 1 | call setline(l,' *Created Time  : '.strftime('%c'))
let l = l + 1 | call setline(l,' *File Name     : '.expand('%c'))
let l = l + 1 | call setline(l,' *Problem')
let l = l + 1 | call setline(l,' *Get:')
let l = l + 1 | call setline(l,'***********************1599664856@qq.com**********************/')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'#include <cstdio>')
let l = l + 1 | call setline(l,'#include <cstring>')
let l = l + 1 | call setline(l,'#include <iostream>')
let l = l + 1 | call setline(l,'#include <algorithm>')
let l = l + 1 | call setline(l,'#include <vector>')
let l = l + 1 | call setline(l,'#include <queue>')
let l = l + 1 | call setline(l,'#include <set>')
let l = l + 1 | call setline(l,'#include <map>')
let l = l + 1 | call setline(l,'#include <string>')
let l = l + 1 | call setline(l,'#include <cmath>')
let l = l + 1 | call setline(l,'#include <cstdlib>')
let l = l + 1 | call setline(l,'#include <ctime>')
let l = l + 1 | call setline(l,'#include <stack>')
let l = l + 1 | call setline(l,'using namespace std;')
let l = l + 1 | call setline(l,'typedef pair<int, int> pii;')
let l = l + 1 | call setline(l,'typedef long long ll;')
let l = l + 1 | call setline(l,'typedef unsigned long long ull;')
let l = l + 1 | call setline(l,'vector<int> vi;')
let l = l + 1 | call setline(l,'#define pr(x) cout << #x << ": " << x << "  " ')
let l = l + 1 | call setline(l,'#define pl(x) cout << #x << ": " << x << endl;')
let l = l + 1 | call setline(l,'#define xx first')
let l = l + 1 | call setline(l,'#define yy second')
let l = l + 1 | call setline(l,'#define sa(n) scanf("%d", &(n))')
let l = l + 1 | call setline(l,'#define rep(i, a, n) for (int i = a; i < n; i++)')
let l = l + 1 | call setline(l,'#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) ')
let l = l + 1 | call setline(l,'const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main(void)')
let l = l + 1 | call setline(l,'{')
let l = l + 1 | call setline(l,'#ifdef LOCAL')
let l = l + 1 | call setline(l,'    //freopen("in.txt", "r", stdin);')
let l = l + 1 | call setline(l,'    //freopen("out.txt", "w", stdout);')
let l = l + 1 | call setline(l,'#endif')
let l = l + 1 | call setline(l,'    cin.sync_with_stdio(false);')
let l = l + 1 | call setline(l,'    ')
let l = l + 1 | call setline(l,'    return 0;')
let l = l + 1 | call setline(l,'}')
endfunc
endif


"the cpp f5 run program
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
        exec "w"
        if &filetype == 'c'
           exec "!g++ % -DLOCAL -o   %<"
           exec "!time ./%<"
        elseif &filetype == 'cpp'
           exec "!g++ % -DLOCAL -o    %<"
           exec "!time ./%<"
        elseif &filetype == 'java'
           exec "!javac %"
           exec "!time java %<"
        elseif &filetype == 'sh'
           :!time bash %
        elseif &filetype == 'python'
        exec "!time python3.5 %"
        endif
endfunc

"inoremap ( ()<ESC>i
"inoremap [ []<ESC>i
"inoremap { {}<ESC>i





"""""""""vundle插件配置文件

set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
"Plugin 'ascenator/L9', {'name': 'newL9'}


"一些自己的插件
Plugin 'altercation/vim-colors-solarized'
Plugin 'Lokaltog/vim-powerline'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'nathanaelkane/vim-indent-guides'  "可视化缩进
Plugin 'scrooloose/nerdcommenter' "cc, cu 批量注释
Plugin 'valloric/YouCompleteMe'
Plugin 'Raimondi/delimitMate' "缩进
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line




"""""""""""""Indent Guides 配置"""""""
" 随 vim 自启动
let g:indent_guides_enable_on_vim_startup=1
" 从第二层开始可视化显示缩进
let g:indent_guides_start_level=2
" 色块宽度
let g:indent_guides_guide_size=1
" 快捷键 i 开/关缩进可视化
:nmap <silent> <Leader>i <Plug>IndentGuidesToggle

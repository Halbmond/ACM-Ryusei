"set transparency=11 "透明度
"set background=dark "黑色背景
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
"colorscheme monokai "配色沙漠 还有: desert, torte, solarized, molokai, phd, ron, evening  等经典配色
"Type <:colorscheme> + <Space> + <TAB>.  to list all colorschemes
set showmatch "自动匹配
set ruler "在右下角显示当前行信息
set incsearch "搜索加强
set hlsearch "搜索高亮
set guioptions-=T "一出工具栏
set showcmd "显示出输入的命令
set guifont=Menlo:h15 "字体和大小
set lines=55 "窗口多长，下为多宽
set columns=100
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


"按<F2>自动生成代码设置
if !exists("*SetTitlea")
map <F2> :call SetTitlea()<CR>
func SetTitlea()
let l = 0
let l = l + 1 | call setline(l,'/************************************************')
let l = l + 1 | call setline(l,' *Author*        : Ryusei')
let l = l + 1 | call setline(l,' *Created Time*  : '.strftime('%c'))
let l = l + 1 | call setline(l,'**Problem**:')
let l = l + 1 | call setline(l,'**Analyse**:')
let l = l + 1 | call setline(l,'**Get**:')
let l = l + 1 | call setline(l,'**Code**:')
let l = l + 1 | call setline(l,'*********************************************/')
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
let l = l + 1 | call setline(l,'typedef pair<int, int> PII;')
let l = l + 1 | call setline(l,'typedef long long ll;')
let l = l + 1 | call setline(l,'typedef unsigned long long ull;')
let l = l + 1 | call setline(l,'#define db(x) cout << #x << "=" << x << "  "')
let l = l + 1 | call setline(l,'#define el cout << endl;')
let l = l + 1 | call setline(l,'#define c0 first')
let l = l + 1 | call setline(l,'#define c1 second')
let l = l + 1 | call setline(l,'const int mol = int(1e9) + 7, INF = 0x3f3f3f3f;')
let l = l + 1 | call setline(l,'const int MXN = 1e5 + 13;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main()')
let l = l + 1 | call setline(l,'{')
let l = l + 1 | call setline(l,'#ifdef LOCAL')
let l = l + 1 | call setline(l,'    //freopen("in.txt", "r", stdin);')
let l = l + 1 | call setline(l,'    //freopen("out.txt", "w", stdout);')
let l = l + 1 | call setline(l,'#endif')
" let l = l + 1 | call setline(l,'    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);')
let l = l + 1 | call setline(l,'    ')
let l = l + 1 | call setline(l,'    return 0;')
let l = l + 1 | call setline(l,'}')
endfunc
endif



"按F5一键编译并运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
        exec "w"
        if &filetype == 'c'
           exec "!g++ % -DLOCAL -o   %<"
           exec "!time ./%<"
        elseif &filetype == 'cpp'
           exec "!g++ % -std=c++11 -DLOCAL -Dxiaoai -o    %<"
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

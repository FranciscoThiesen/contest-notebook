Based on the [jakobkogler/Algorithm-DataStructures](https://github.com/jakobkogler/Algorithm-DataStructures)

# contest-notebook 

This repo contains algorithms and data structures that might be useful during programming contest.

## Vim plugin

The algorithms and data structures can easily be pasted into a document using the included Vim plugin.

![demonstration](demonstration.gif)

### Installation

Use [vim-plug](https://github.com/junegunn/vim-plug) or any Vim plugin manager of your choice.
The plugin [fzf](https://github.com/junegunn/fzf) is a requirement.

With vim-plug:

```vim
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'FranciscoThiesen/contest-notebook'
```

### Command/Usage

The plugin defines a single command `AlgDS`.
It can be mapped like this:

```vim
nmap <leader>alg :AlgDS<CR>
```

## Pretty Printer

There are some pretty printer for GDB.
You can activate them by putting the following in your `~/.gdbinit`:

```sh
source ~/.vim/plugged/Algorithm-DataStructures/prettyprint.py
```

## License

WTFPL

# Minishell Issues

## Must

- (DONE) **Environment Variables:**
  - Must update `$SHLVL` and increment by 1 during shell initialization.
  - Must update `$PWD` and `$OLDPWD` when using the `cd` command.

- (DONE) **Echo:**
  - Running `echo "$"` must print `$`.

- (DONE) **Exit Status:**
  - The `exit_status` must equal `2` after a bad or incorrect syntax command.

- (DONE) **Export:**
  - Must print sorted rows of `declare -x var`.

- (DONE) **`cd` (chdir) Issue:**
  1. Create a directory:
     ```bash
     mkdir tmp
     ```
  2. Navigate into it:
     ```bash
     cd tmp
     mkdir tmp2
     cd tmp2
     ```
  3. Try removing the parent directory:
     ```bash
     rm -rf ../../tmp
     ```
     The shell **should not exit** in this scenario.

---

## Should

- **Tilde Expansion:**
  - The shell should support `~` expansion.

- **Parsing:**
  - Parsing should behave like Bash, e.g.:
    ```bash
    export cmd="ls -la"
    $cmd  # Should execute `ls -la`.
    ```

- **Ambiguous Redirect:**
  - For a command like:
    ```bash
    <$abc
    ```
    The shell should log an error: `ambiguous redirect`.

---

## Boat's Notes

- **Signals:**
  - Check signal handling rigorously.
  - Example: `^\` in interactive mode triggers a newline. Verify if this behavior is correct.

- **Child Processes:**
  - Avoid zombie processes:
    ```bash
    yes | cat
    ps -a
    ```
---

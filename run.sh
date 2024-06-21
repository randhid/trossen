#!/usr/bin/env bash

# bash safe mode
set -euo pipefail

cd $(dirname $0)
exec ./my-base $@
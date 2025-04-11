# makeBinaryWrapper

For testing new makeBinaryWrapper change separate from nixpkgs

This is useful because EVERYTHING uses makeBinaryWrapper,
so if you replace makeBinaryWrapper, in YOUR WHOLE nixpkgs, you will build EVERYTHING from source.

So, import this as a flake input with flake = false, or using fetchGit and call `pkgs.callPackage this {}` on it

For more info, see: https://github.com/NixOS/nixpkgs/pull/397604

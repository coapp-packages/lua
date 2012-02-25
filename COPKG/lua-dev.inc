@import "version.inc" ;
@import "outercurve.inc" ;

package {
    name: "lua-dev[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";

    display-name: "Lua developer library";
}

metadata {
    summary: "The Lua developer library";
    description: @"Lua is a powerful, fast, lightweight, embeddable scripting language.
Lua combines simple procedural syntax with powerful data description constructs based on associative arrays and extensible semantics. Lua is dynamically typed, runs by interpreting bytecode for a register-based virtual machine, and has automatic memory management with incremental garbage collection, making it ideal for configuration, scripting, and rapid prototyping."; 

    icon: @"lua.png";
    
    author-version : "5.2.0";
    bug-tracker: "https://github.com/coapp-packages/lua/issues";
    stability : "0";
    licenses : {
        MIT
    };
}

files[libs] {
    root: @"..\Release\${arch}\";
    
    include: {
        "lua5.2.lib",
    };
    
    trim-path: all;
};

requires {
    package: "lua-dev-common-${package-version}-any-${Package.PublicKeyToken}";
    package: "lua[${flavor}]-${package-version}-${Package.Architecture}-${Package.PublicKeyToken}";
}

developer-library[lua] {
    libraries : {
        libs
    };
}
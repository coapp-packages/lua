@import "version.inc";
@import "outercurve.inc";

package {
    name: "lua[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";
    
    display-name: "Lua";
    location: "http://coapp.org/repository/${OutputFilename}";

    feed: "http://coapp.org/repository/packages.atom.xml";
    publisher: "CoApp Project";
}

files[exes] {
    root: @"..\Release\${arch}\";
    
    include: {
        "lua.exe",
        "luac.exe",
    };
    
    trim-path: all;
};


files[dlls] {
    root: @"..\Release\${arch}\";
  
    include: {
        "lua5.2.dll",
    };
    
    trim-path: all;
};

license[MIT] {
    license-url: "http://www.lua.org/license.html";
    license-type: "MIT";
}

files[files-to-sign] {
    include: { 
        exes,
        dlls
    };    
}

provides {
    feature: "languages.lua" = "5.2.0";
}

metadata {
    summary: "The Lua programming language";
    description:  @"Lua is a powerful, fast, lightweight, embeddable scripting language.
Lua combines simple procedural syntax with powerful data description constructs based on associative arrays and extensible semantics. Lua is dynamically typed, runs by interpreting bytecode for a register-based virtual machine, and has automatic memory management with incremental garbage collection, making it ideal for configuration, scripting, and rapid prototyping."; 

    icon: @"lua.png";
    
    author-version : "5.2.0";
    bug-tracker: "https://github.com/coapp-packages/lua/issues";
    stability : "0";
    licenses : {
        MIT
    };
}

compatability-policy {
    minimum: "5.2.0.0";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "5.2",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}

application {
    include : {
        exes,
    };
}

manifest[things-that-need-them] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        lua
    };
    
    include : { 
        exes
    };
}

assembly[lua] {
    include : {
        dlls
    };
}

package-composition {
    symlinks : { 
        exes => @"${bin}\${each.Name}" = @"${packagedir}\${each.Name}";
    };
}

signing {
    attributes : {
        company="Outercurve Foundation",
        description="${Package.PackageDetails.Summary}",
        product-name="lua",
        product-version="${package-version}",
        file-version="${package-version}",
    };
    
    replace-signature: true; 
    include: { 
        files-to-sign
    };    
}
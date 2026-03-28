includes("volkrnl")

target("qvirt-aarch64")
    set_kind("phony")
    add_deps("volkrnl-qvirt-aarch64")

target("prepare-sys")
    set_kind("phony")
    on_run(function (target)
        import("scripts.prepinitfs")
        prepinitfs.prepare_initfs()
    end)
    

"use strict";(self.webpackChunkmodio_docs=self.webpackChunkmodio_docs||[]).push([[5854],{2843:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>s,contentTitle:()=>a,default:()=>p,frontMatter:()=>r,metadata:()=>c,toc:()=>d});var i=n(4848),o=n(8453);const r={id:"linux-cmake-integration",title:"CMake Integration",slug:"/cppsdk/linux/cmake-integration",sidebar_position:1,custom_edit_url:"https://github.com/modio/modio-sdk-internal/blob/develop/platform/linux/doc/cmake-integration.mdx"},a=void 0,c={id:"game-integration/cppsdk/linux/linux-cmake-integration",title:"CMake Integration",description:"Inside a CMake project",source:"@site/public/en-us/game-integration/cppsdk/linux/cmake-integration.mdx",sourceDirName:"game-integration/cppsdk/linux",slug:"/cppsdk/linux/cmake-integration",permalink:"/cppsdk/linux/cmake-integration",draft:!1,unlisted:!1,editUrl:"https://github.com/modio/modio-sdk-internal/blob/develop/platform/linux/doc/cmake-integration.mdx",tags:[],version:"current",sidebarPosition:1,frontMatter:{id:"linux-cmake-integration",title:"CMake Integration",slug:"/cppsdk/linux/cmake-integration",sidebar_position:1,custom_edit_url:"https://github.com/modio/modio-sdk-internal/blob/develop/platform/linux/doc/cmake-integration.mdx"},sidebar:"sidebar",previous:{title:"Getting Started",permalink:"/cppsdk/linux/getting-started"},next:{title:"Getting Started",permalink:"/cppsdk/macos/getting-started"}},s={},d=[{value:"Inside a CMake project",id:"inside-a-cmake-project",level:2}];function l(e){const t={code:"code",h2:"h2",p:"p",pre:"pre",...(0,o.R)(),...e.components};return(0,i.jsxs)(i.Fragment,{children:[(0,i.jsx)(t.h2,{id:"inside-a-cmake-project",children:"Inside a CMake project"}),"\n",(0,i.jsxs)(t.p,{children:["Unzip the archive. Confirm ",(0,i.jsx)(t.code,{children:"your_project"})," uses CMake 3.20 or later."]}),"\n",(0,i.jsx)(t.pre,{children:(0,i.jsx)(t.code,{className:"language-cmake",children:"cmake_minimum_required(VERSION 3.20)\n"})}),"\n",(0,i.jsxs)(t.p,{children:["Specify the target platform with ",(0,i.jsx)(t.code,{children:"LINUX"}),"."]}),"\n",(0,i.jsx)(t.pre,{children:(0,i.jsx)(t.code,{className:"language-cmake",children:"set (MODIO_PLATFORM LINUX)\n"})}),"\n",(0,i.jsx)(t.p,{children:"Add the SDK subdirectory to your project"}),"\n",(0,i.jsx)(t.pre,{children:(0,i.jsx)(t.code,{className:"language-cmake",children:"add_subdirectory(<modio-sdk folder> EXCLUDE_FROM_ALL)\ntarget_compile_features(your_project PUBLIC cxx_std_17)\n"})}),"\n",(0,i.jsx)(t.p,{children:"Link the library to your project."}),"\n",(0,i.jsx)(t.p,{children:"To use the header-only configuration:"}),"\n",(0,i.jsx)(t.pre,{children:(0,i.jsx)(t.code,{className:"language-cmake",children:"target_link_libraries(your_project PUBLIC modio)\n"})}),"\n",(0,i.jsx)(t.p,{children:"Or to use the static library configuration:"}),"\n",(0,i.jsx)(t.pre,{children:(0,i.jsx)(t.code,{className:"language-cmake",children:"target_link_libraries(your_project PUBLIC modioStatic)\n"})}),"\n",(0,i.jsxs)(t.p,{children:["To simplify the CMake configuration, the folder ",(0,i.jsx)(t.code,{children:"cmake/"})," has the file ",(0,i.jsx)(t.code,{children:"CMakePresets.json"})," with the basic configuration required to guide the mod.io SDK compilation using the Linux SDK. If you copy that file to the folder root, it can be used as follows:"]}),"\n",(0,i.jsx)(t.pre,{children:(0,i.jsx)(t.code,{className:"language-cmake",children:"cmake --preset linux\n"})})]})}function p(e={}){const{wrapper:t}={...(0,o.R)(),...e.components};return t?(0,i.jsx)(t,{...e,children:(0,i.jsx)(l,{...e})}):l(e)}},8453:(e,t,n)=>{n.d(t,{R:()=>a,x:()=>c});var i=n(6540);const o={},r=i.createContext(o);function a(e){const t=i.useContext(r);return i.useMemo((function(){return"function"==typeof e?e(t):{...t,...e}}),[t,e])}function c(e){let t;return t=e.disableParentContext?"function"==typeof e.components?e.components(o):e.components||o:a(e.components),i.createElement(r.Provider,{value:t},e.children)}}}]);
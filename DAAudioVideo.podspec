Pod::Spec.new do |s|
  s.name = "DAAudioVideo"
  s.version = "1.2.6"
  s.summary = "A short description of TGCommonBaseModule."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"liubin"=>"liubin361163@163.com"}
  s.homepage = "https://gitee.com/tange-ai/tgopendaaudiovideo.git"
  s.description = "TODO: Add long description of the pod here."
  s.xcconfig = {"ENABLE_BITCODE"=>"NO"}
  s.source           = { :git => 'https://gitee.com/tange-ai/tgopendaaudiovideo.git', :tag => s.version.to_s }
#  s.compiler_flags ='-DLINUX','-D__MAC_OS__','-DWEBRTC_MAC','-D_M_X64'
  s.ios.deployment_target    = '12.1'
#  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' ,'DEVELOPMENT_TEAM' => 'UAL776976T','OTHER_CFLAGS' => '-DLINUX -D__MAC_OS__'}
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64','DEVELOPMENT_TEAM' => 'UAL776976T','OTHER_CFLAGS' => '-DLINUX -D__MAC_OS__' }
  s.source_files = 'ios/DAAudioVideo.framework/Headers/*.h'
  s.ios.vendored_frameworks   = 'ios/**/*.framework'
  s.frameworks = 'UIKit'
  s.libraries = 'bz2','c++','iconv','z'
  s.dependency 'CocoaLumberjack'
  s.dependency 'TGFFmpegKit', '6.0'
end

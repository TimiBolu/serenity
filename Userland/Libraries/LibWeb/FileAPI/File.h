/*
 * Copyright (c) 2022-2023, Kenneth Myhra <kennethmyhra@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/FileAPI/Blob.h>

namespace Web::FileAPI {

struct FilePropertyBag : BlobPropertyBag {
    Optional<i64> last_modified;
};

class File : public Blob {
    WEB_PLATFORM_OBJECT(File, Blob);

public:
    static WebIDL::ExceptionOr<JS::NonnullGCPtr<File>> create(JS::Realm&, Vector<BlobPart> const& file_bits, String const& file_name, Optional<FilePropertyBag> const& options = {});
    static WebIDL::ExceptionOr<JS::NonnullGCPtr<File>> construct_impl(JS::Realm&, Vector<BlobPart> const& file_bits, String const& file_name, Optional<FilePropertyBag> const& options = {});

    virtual ~File() override;

    // https://w3c.github.io/FileAPI/#dfn-name
    String const& name() const { return m_name; }
    // https://w3c.github.io/FileAPI/#dfn-lastModified
    i64 last_modified() const { return m_last_modified; }

private:
    File(JS::Realm&, ByteBuffer, String file_name, String type, i64 last_modified);

    virtual void initialize(JS::Realm&) override;

    String m_name;
    i64 m_last_modified { 0 };
};

}
